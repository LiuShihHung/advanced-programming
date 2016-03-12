#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int s[54][24] ;

int N ;

int a[10000000], l ;

int t[54][24] ;

int b[54] ;

int num  ;

int profit(int *p , int n , int j ){

  int i ,k ;

  int max  , count  ;

  max = 0 ; count = 0 , num = 0 ;

   t[j][0]=0, b[j] = 1;

  for(i=0 ;i < n ; i++){

    count += 10 -p[i] ;

    if(count > max){

        max = count  ;

        b[j] = 1 ;

        t[j][0] = i+1 ;

    }

    else if(count == max) t[j][b[j]++] = i+1 ;

  }

   return max ;
}



int comp (const void *a , const void *b){

int i1 , i2 ;

i1 = *(int*) a;

i2 = *(int*) b ;

if(i1 > i2) return 1 ;

else return -1;


}

void dfs(int n, int k){
    if(n == N){
        a[l ++] = k;
        return ;
    }
    int i;
    for(i = 0; i < b[n]; i ++)
        dfs(n+1, k+t[n][i]);
}




int main(){

 int W = 0 ;

int profits[51] = {0} ;

while(scanf("%d",&N) && N){

    memset(b, 0, sizeof(b));

  int n , i , j  , sum ;


  int p[51][21] ={0}  ;

  memset(profits, 0, sizeof(profits));

  sum = 0 ;
  l=0 ;

  for(i=0 ; i<N ; i++){

        scanf("%d" , & n ) ;

        for(j=0 ; j<n ; j++){

          scanf("%d", &p[i][j]) ;

        }
     profits[i] = profit(p[i] , n , i) ;

  }

   for(i=0 ; i<N ; i++){

    sum +=  profits[i] ;

   }
   if(W!= 0 ) printf("\n") ;

   printf("Workyards %d\n" ,++ W)   ;

   printf("Maximum profit is %d.\n", sum) ;

    printf("Number of pruls to buy:");


    dfs(0,0) ;

    qsort(a , l , sizeof(int) , comp) ;

   int x = 0;

        for(i = 0; i < l; i ++){

            if(i==0 || a[i]!=a[i-1]) {

             x ++ ;

             printf(" %d", a[i]);

            }

            if(x == 10) break;

        }

    printf("\n") ;
}


return 0 ;
}
