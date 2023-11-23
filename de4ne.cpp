#include<stdio.h>
#include<stdlib.h>
int main(){
	int row,col;
	printf("Nhap vao so dong va so cot: ");
	scanf("%d %d",&row,&col);
	int number[row][col];
	int choice;
	int updateNumber,updateCol;
	int estimatedNumber=0;
	int max,min;
	do{
		printf("\t\t\tMENU\t\t\n");
		printf("1. Nhap cac phan tu cua mang\n");
		printf("2. In ra cac gia tri cua mang theo ma tran\n");
		printf("3. Tinh so luong cac phan tu chia het cho 5 trong mang\n ");
		printf("4. In ra cac phan tu co gia tri lon nhat, nho nhat nam tren duong bien, duong cheo phu\n");
		printf("5. Su dung thuat toan sap xep chon sap xep cac phan tu giam dan\n");
		printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
		printf("7. Su dung thuat toan chen sap xep duong cheo phu mang tang dan\n");
		printf("8. Nhap gia tri mang 1 chieu gom n phan tu va so cot muon chen\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				for(int n=0;n<row;n++){
					for(int m=0;m<col;m++){
						printf("Nhap gia tri number[%d][%d] = ",n,m);
						scanf("%d",&number[n][m]);
					}
				}
			break;
			case 2:
				for(int n=0;n<row;n++){
					for(int m=0;m<col;m++){
						printf("%d\t",number[n][m]);
					}
					printf("\n");
				}
			break;
			case 3:
				for(int n=0;n<row;n++){
					for(int m=0;m<col;m++){
						if(number[n][m]%5==0){
							printf("%d\t",number[n][m]);
						}
					}
				}
			break;
			case 4:
				max=number[0][0];
				min=number[0][0];
				for(int n=0;n<row;n++){
					for(int m=0;m<col;m++){						
						if(n==0||n==row-1||m==0||m==col-1){							
							if(max<number[n][m]){
								max=number[n][m];
							}
							if(min>number[n][m]){
								min=number[n][m];
							}
						}
					}
				}
				printf("Gia tri lon nhat tren duong bien la: %d\n",max);
				printf("Gia tri nho nhat tren duong bien la: %d\n",min);
				max=number[0][row-1];
				min=number[0][row-1];
				if(row==col){
					for(int n=0;n<row;n++){
						for(int m=0;m<col;m++){
							if(n==m){								
								if(max<number[n][m]){
									max=number[n][m];
								}
								if(min>number[n][m]){
									min=number[n][m];
								}								
							}
						}
					}
					printf("Gia tri lon nhat tren duong chao chinh la: %d\n",max);
					printf("Gia tri nho nhat tren duong chao chinh la: %d\n",min);
					max=number[0][col-1];
					min=number[0][col-1];
					for(int n=0;n<row;n++){
						for(int m=0;m<col;m++){
							if(n+m==row-1){
								if(max<number[n][m]){
									max=number[n][m];
								}
								if(min>number[n][m]){
									min=number[n][m];
								}
							}
						}
					}
					printf("Gia tri lon nhat tren duong chao phu la: %d\n",max);
					printf("Gia tri nho nhat tren duong chao phu la: %d\n",min);
				}else{
					printf("Khong co duong cheo chinh va duong cheo phu\n");
				}
			break;
			case 5:
				for(int n=0;n<row-1;n++){
					for(int m=0;m<col-1;m++){
						for(int i=n+1;i<row;i++){
							for(int j=m+1;j<col;j++){
								if(number[n][m]>number[i][j]){
									int temp=number[n][m];
									number[n][m]=number[i][j];
									number[i][j]=temp;
								}
							}
						}
					}
				}
			break;
			case 6:
				for(int n=0;n<row;n++){
					for(int m=0;m<col;m++){
						for(int n=2;n<=number[n][m]/2;n++){
							if(number[n][m]%n==0){
								estimatedNumber++;
							}
						}
						if(estimatedNumber==0){
							printf("Day la so nguyen to");
						}else{
							printf("Day khong phai la so nguyen to");
						}
					}
				}
			
			case 9:
				exit(0);
			default:
				printf("Khong hop le");
		}
	}while(1==1);
}
