void swap(int* pi, int* pj) {
   int swap;
   swap = *pi;
   *pi = *pj;
   *pj = swap;
}

//Set a value to zero (actually can be quite handy when )
void zero(int* add){
    *add = 0;
}