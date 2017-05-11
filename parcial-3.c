void mezclar(int *origenA, int *origenB, int *Destino){
	while (*origenA != -1 && *origenB != -1){
		if (*origenA < *origenB){
			*Destino = *origenA;
			origenA++;
		} else {
			*Destino = *origenB;
			origenB++;
		}
		Destino++;
	}
	while (*origenA != -1){
		*Destino = *origenA;
		Destino++;
		origenA++;
	}
	while (*origenB != -1){
		*Destino = *origenB;
		Destino++;
		origenB++;
	}
	*Destino = -1;
}
