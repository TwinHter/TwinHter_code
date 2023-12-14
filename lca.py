import sys
sys.setrecursionlimit(2000010)
n, q = list(map(int, input().strip().split()))
lim = 21
a = [[] for _ in range(n+10)]
h =[0]*(n+10)
up = [[0]*(n+10) for _ in range(lim)]
 
def dfs(u, f) :
  up[0][u] = f
  h[u] = h[f]+1
  for i in range(1, lim, 1):
    up[i][u] = up[i-1][up[i-1][u]]
  
  for i in range(len(a[u])) :
    if(a[u][i] != f): dfs(a[u][i], u)
 
def lca(u, v) :
  if(h[u] > h[v]): u, v = v, u
  dif = h[v]-h[u]
  for i in range(lim-1, -1, -1) :
    if((dif>>i)&1): 
      v = up[i][v]
  
  if(u == v) : return u
  for i in range(lim-1, -1, -1) :
    if(up[i][u] != up[i][v]) : 
      u, v = up[i][u], up[i][v]
  
  return up[0][u]
 
for _ in range(n-1) :
  u, v = list(map(int, input().strip().split()))
  u-=1; v-=1;
  a[u].append(v)
  a[v].append(u)
 
h[0] = 0
dfs(0, 0)
# for u in range(n) :
#   for v in range(n) :
#     print(u, v, lca(u, v))
for _ in range(q) :
  u, v = list(map(int, input().strip().split()))
  u-=1; v-=1;
  #print(u, v)
  uv = lca(u, v)
  print(h[u]+h[v]-2*h[uv])
