void swap(char* x, char* y) {
	char* a = x; 
	char* c = y;

	char dl = *a;
	/*Non posso fare questa cosa che segue
	 *a = *c;
	 *c = dl;
	*/
	char dh = *c;
	*a = dh;
	*c = dl;
}