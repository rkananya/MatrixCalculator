#include <stdio.h>
#include<math.h>
#include <stdlib.h>
//function to add two matrices
//arguments-matrices 1,2,no. of rows and columns
void add(int a[][10],int b[][10],int r,int c)
{
    int i,j,sum[10][10];
    //traversing rows
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)//accessing columns elements of rows
        {
            sum[i][j]=a[i][j]+b[i][j];//sum element is sum of respective elements in both matrices
        }
    }
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",sum[i][j]);//printing sum matrix
        }printf("\n");
    }
}
//function to subtract as similar as add
void subtract(int a[][10],int b[][10],int r,int c)
{
    int i,j,diff[10][10];
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            diff[i][j]=a[i][j]-b[i][j];
        }
    }
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",diff[i][j]);
        }printf("\n");
    }
}
//function to multiply matrixes
//arguments-matrix A,B,row of A(r1)and column of B(c2) and column of A or row of B
//resultant product matrix would have r1 x c2 dimension
//multiplication is only possible when c1=r2
void multiply(int a[][10],int b[][10],int r1,int c2,int r)
{
    int i,j,k,prod[10][10],sum=0;
    //accessing the row of A
    for (i=0;i<r1;i++)
    {
        //accessing the column of B
        for(j=0;j<c2;j++)
        {   //reinitializing sum as 0 while calculating for new product matrix element
            sum=0;
            //this loop is the third dependency that helps us access the particular elements of multiplication
            //EG:in A first row first column element multiplied with in B first row first col.and
            //first row second col.element with first 'col.'second 'row' element...
            for (k=0;k<r;k++)
            {
                sum=sum+a[i][k]*b[k][j];
            }prod[i][j]=sum;
        }
    }
    for (i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",prod[i][j]);
        }printf("\n");
    }
}
//function to find transpose
//arguments- matrix A,no of rows and cols
 void transpose(int a[][10],int r,int c)
 {
     int i,j;
     int trans[10][10];
     for (i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
         {
             trans[i][j]=a[j][i];//transposing--the row elements becomes the column ele.and vice versa
             printf("%d\t",trans[i][j]);
         }printf("\n");
     }
 }
 //finding the cofactor matrix
 //arguments-matrix A,matrix to store cofactor ,the particular rows and cols of finding cofac.and the n -no of rows or cols of A
 //A-input matrix
 void cofactor(int a[][10],int temp[][10],int p,int q,int n)
 {
     int i=0,j=0,row,col;
     //row-to traverse across rows of A
     for(row=0;row<n;row++)
    {
        //col-to traverse across cols of A
        for(col=0;col<n;col++)
            {
                //taking elements excluding the particular row and column specified
                if(row!=p&&col!=q)
                {
                    //TEMP--in first row the n-1 columns are filled
                    //note: its post fix so first it assigns and then increments
                    //temp[0][0] then immediately j becomes 1
                    temp[i][j++]=a[row][col];
                    //if the number of columns of A is reached
                    //pointer goes to next row and j becomes 0
                    if(j==n-1)
                    {
                        i++;
                        j=0;
                    }
                }
            }
    }
}
//finding determinant
//arguments- Matrix A and no of rows or the columns of A
 int det(int mat[10][10], int n)
{
    // Initialize result
    int D = 0;

    //  Base case : if matrix contains
    // single element
    if (n == 1)
        return mat[0][0];

    // To store cofactors
    int temp[10][10];

    // To store sign multiplier
    int sign = 1;

    // Iterate for each element of
    // first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        cofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f]
             * det(temp, n - 1);

        // Terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}
//finding adjoint
//arguments-matrix A ,storing adjoint matrix,the no. of  rows and cols,choice whether to  print or not
//here choice is added because if the user calls it to find adj then it is to be printed
//Also we use this to find inverse so there we needn't  print
 void adjoint(int a[][10],int ad[][10],int n,char ch)
 {
     int temp[10][10],i,j;
     if(n==1)
     {
         ad[0][0]=1;
         return;
     }
     int sign =1;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             //to find minor matrix
             cofactor(a,temp,i,j,n);
             //sign formula is (-1)^(i+j)
             //so if i+j is even its 1 else -1
             sign=(i+j)%2==0?1:-1;
             ad[i][j]=sign*det(temp,n-1);//sign x determinant of minor elements
         }
     }
     //choice of printing
     if(ch=='y')
        {
        printf("\nAdjoint:\n");
        display(ad,n,n);
       }
 }
 //multiply the input matrix with a scalar quantity
 void scalarMultiplication(int a[][10],int t[][10],int r,int c,int s)
 {
     int i,j;
     for(i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
         {
             //multiplying scalar with each element
            t[i][j]=s*a[i][j];
         }
     }
     //print the result
     for(i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
         {
             printf("%d\t",t[i][j]);
         }printf("\n");
     }
 }
 //finding inverse of input matrix
 void inverse(int a[][10],int n)
 {
     //inverse=(1/det)x adj A
     int i,j,ad[10][10],d;
     float ai[10][10];
     //determinant:
     d=det(a,n);
     //adjoint
     //adjoint matrix stored in ad matrix
     //# not to print
     adjoint(a,ad,n,'#');
      for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
            ai[i][j]=(float)ad[i][j]/(float)d;//typecasting it as float
         }
     }
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
            printf("%f\t",ai[i][j]);
         }printf("\n");
     }
 }
 void read(int a[][10],int r,int c)
 {
     int i,j;
     for(i=0;i<r;i++)
       {
        for(j=0;j<c;j++)
          {
            scanf("%d",&a[i][j]);
          }
       }
 }
 void display(int a[][10],int r,int c)
 {
     int i,j;
     for(i=0;i<r;i++)
       {
        for(j=0;j<c;j++)
          {
            printf("%d\t",a[i][j]);
          }printf("\n");
       }
 }
 //(x-X)
 void deviation(int a[],int d[],int n)
 {
     int i,sum,mean;
     for(i=0;i<n;i++)
        sum+=a[i];
    mean=sum/n;
    for(i=0;i<n;i++)
        d[i]=a[i]-mean;
 }
 int var(int x[],int n)
 {
    int sum=0,dx[100],v;
    deviation(a,dx,n);
    for(int i=0;i<n;i++)
        sum=sum+(pow(dx[i],2));
    v=sum/n-1;
    return v;
 }
 int main()
 {
     int a[10][10],b[10][10],r1,c1,r2,c2,ch,s,d,n;
     //menu
     printf("WHAT WOULD YOU LIKE TO OPERATE: \n1=sum\n2=difference\n3-product\n4=transpose\n5=determinant\n6=scalar mutiplication\n7=inverse\n8-adjoint\n9-variance\n");
     //choice of user
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:
         //addition
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        printf("\nenter rows and columns of matrix B");
        scanf("%d%d",&r2,&c2);
        //if rows and cols are not identical sum not possible
        if(r1!=r2||c1!=c2)
        {
            printf("sorry! addition cannot be done");
        }
        else{
            printf("Enter elements for A");
            read(a,r1,c1);
            printf("Enter elements for B");
            read(b,r2,c2);
            printf("\nMatrix A\n");
            display(a,r1,c1);
            printf("Matrix B\n");
            display(b,r2,c2);
            printf("The sum:\n");
            add(a,b,r1,c1);
        }break;
        case 2:
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        printf("\nenter rows and columns of matrix B");
        scanf("%d%d",&r2,&c2);
        if(r1!=r2||c1!=c2)
        {
            printf("sorry! subraction cannot be done");
        }
        else{
            printf("Enter elements for A");
            read(a,r1,c1);
            printf("Enter elements for B");
            read(b,r2,c2);
            printf("\nMatrix A\n");
            display(a,r1,c1);
            printf("Matrix B\n");
            display(b,r2,c2);
            printf("The difference:\n");
            subtract(a,b,r1,c1);
        }break;
        case 3:
        //multiplication
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        printf("\nenter rows and columns of matrix B");
        scanf("%d%d",&r2,&c2);
        //if row of B is not equal to col of A ,multiplication not possible
        if(r2!=c1)
        {
            printf("sorry! multiplication cannot be done");
        }
        else{
            printf("Enter elements for A");
            read(a,r1,c1);
            printf("Enter elements for B");
            read(b,r2,c2);
            printf("\nMatrix A\n");
            display(a,r1,c1);
            printf("Matrix B\n");
            display(b,r2,c2);
            printf("The product:\n");
            multiply(a,b,r1,c2,r2);
        }break;
        case 4:
            //transpose
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        printf("Enter elements for A");
        read(a,r1,c1);
        printf("\nMatrix A\n");
        display(a,r1,c1);
        printf("The transpose:\n");
        transpose(a,r1,c1);
        break;
        //determinant
        case 5:
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        //determinant found only for square matrix
        if(r1!=c1)
        {
            printf("sorry! determinant cannot be found");
        }
        else{
            printf("Enter elements for A");
            read(a,r1,c1);
            printf("\nGiven Matrix\n");
            display(a,r1,c1);
            printf("find:\n");
            printf("The determinant: %d\n",det(a,r1));
        }break;
        case 6:
            //scalar multiplication
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        printf("enter the scalar quantity:\n");
        scanf("%d",&s);
        printf("Enter elements for A");
        read(a,r1,c1);
        printf("\nMatrix A\n");
        display(a,r1,c1);
        printf("The scalar multiplied product:\n");
        scalarMultiplication(a,b,r1,c1,s);
        break;
        case 7:
            //inverse
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        //if square matrix then inverse is found
        if(r1!=c1)
        {
            printf("sorry! inverse cannot be found");
        }
        else{
            printf("Enter elements for A");
            read(a,r1,c1);
            printf("\nGiven Matrix\n");
            display(a,r1,c1);
            d=det(a,r1);
            //if determinant is 0 then 1/det is not defined
            if(d==0)
                printf("determinant zero hence inverse doesn't exist\n");
            else
                inverse(a,r1);
        }
        break;
        case 8:
            //adjoint
        printf("\nenter rows and columns of matrix A");
        scanf("%d%d",&r1,&c1);
        //found only for square matrices
        if(r1!=c1)
        {
            printf("sorry! adjoint cannot be found");
        }
        else{
            printf("Enter elements for A");
            read(a,r1,c1);
            printf("\nGiven Matrix\n");
            display(a,r1,c1);
            adjoint(a,b,r1,'y');
        }break;
        case 9:
            printf("Variance\n");
            printf("enter n: ");
            scanf("%d",&n);

            printf("")

        default:
            printf("enter a valid input");
            break;
    }
    return 0;
 }


