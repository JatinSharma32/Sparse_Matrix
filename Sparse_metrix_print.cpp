#include<stdio.h>


int main(){
	int row,col;
	printf("Enter the row and column: ");
	scanf("%d %d",&row,&col);
	int Arr[row][col];
	printf("\nEnter the Elements: ");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			//To input array elements
			scanf("%d",&Arr[i][j]);
		}
	}
	int count_NonZero=0,count_Zero=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(Arr[i][j]==0){
				//Counting the Zero elements in matrix
				count_Zero++;
			}
			else if(Arr[i][j]!=0){//Counting the NON Zero elements in matrix
				count_NonZero++;
			}
		}
	}
	if(count_Zero>count_NonZero){
		printf("\nThis matrix is a Sparse Matrix\nNumber of Zeros and Non zeros are %d and %d.\n\nARRAY:\n",count_Zero,count_NonZero);
		for(int i=0;i<row;i++){
		    for(int j=0;j<col;j++){
		    	printf("%d ",Arr[i][j]);
		    }
		    printf("\n");
	    }
	    // Converting to Sparse matrix
	    // Lets declare a Empty 2D matrix
	    int Sparse_Matrix[count_NonZero+1][3];
	    //Lets fill the 1st row with already known values
	    Sparse_Matrix[0][0]=row;
	    Sparse_Matrix[0][1]=col;
	    Sparse_Matrix[0][2]=count_NonZero;
	    int ADD_Row=1;
	    for(int i=0;i<row;i++){
	    	for(int j=0;j<col;j++){
	    		if(Arr[i][j]!=0){
	    			Sparse_Matrix[ADD_Row][0]=i+1;
					Sparse_Matrix[ADD_Row][1]=j+1;
	    			Sparse_Matrix[ADD_Row][2]=Arr[i][j];
	    			ADD_Row++;
				}
			}
		}
		printf("\nSparse Matrix:\n");
		for(int i=0;i<count_NonZero+1;i++){
	    	for(int j=0;j<3;j++){
	    		printf("%d ",Sparse_Matrix[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("\nThis matrix is Not a Sparse Matrix\nNumber of Zeros and Non zeros are %d and %d.\n\nARRAY:\n",count_Zero,count_NonZero);
	}
}

