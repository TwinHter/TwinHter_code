ll inv(ll v, ll MOD){
	if (v<=1) return v;
	return inv(MOD%v, MOD)*(MOD-MOD/v)%MOD;
}
