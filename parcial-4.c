int comparar(char* CadenaA, char* CadenaB){
	while (*CadenaA != '\0' && *CadenaB != '\0'){
  	if (*CadenaA < *CadenaB)
    	return 1;
		else if (*CadenaA > *CadenaB)
			return -1;
		CadenaA++;
		CadenaB++;
	}
	if (*CadenaA == '\0' && *CadenaB == '\0')
		return 0;
	else if (*CadenaA != '\0')
		return -1;
	else
		return 1;
