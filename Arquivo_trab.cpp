//Matheus Joaquim Balan RA:21110925-2
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void Menu_Principal();
void Menu_Dolar();
void Dolar_Reais();
void Tira_Ponto();
void Troca_Ordem();
void ClassDesc();
void Mostra_Tabela();
void ClassCod();
void Busca();
void Menu_Consulta();
void Busca_bi();

//------------------------------------------------------
void ler_arquivo(){
int n;
  arqu = fopen("icompy.txt", "r");     
  if (arqu == NULL) 
      printf("Problemas na abertura do arquivo\n");
  else { 
	  x=0; 
      while (!feof(arqu)) {
	    conta++; 
        fgets(lin, 200, arqu);
        if (conta>7){
          if (lin[strlen(lin)-1]=='\n')
              lin[strlen(lin)-1]='\0'; 
          
          for (n=1; n<=7; n++){
             codi[x][n-1]=lin[n]; 
          }
          if(codi[x][0]==' '){
            for(j=0;j<=6;j++){ 
              codi[x][j]=codi[x][j+1];
            }   
          }
          if(codi[x][0]==' '){
            for(j=0;j<=6;j++){ 
              codi[x][j]=codi[x][j+1];
            }   
          }
          if(codi[x][6]==' '){
             codi[x][6]='\0';
           }else{
              if(codi[x][5]==' '){                   
              codi[x][5]='\0'; 
            }else{
                if(codi[x][4]==' '){
                     codi[x][4]=='\0';
                }else{  
                   codi[x][7]='\0';
                }
            }
           }
           
          for (n=10; n<=66; n++){
             desc[x][n-10]=lin[n]; 
          }
          desc[x][57]='\0';
          
          strcpy(precoST,"");
          for (n=67; n<=78; n++){
             precoST[n-67]=lin[n]; 
          }
          precoST[10]='\0';
          dolar[x]=atof(precoST);
          x++; 
        }
             
       }
      fclose(arqu);	
      Tira_Ponto();
  } 
}
//-------------------------------------------------
void Busca(char n[58]){
   char *p;
   int l=1;
     
     system("cls");
     for(x=0;x<=conta-7;x++){
        p=strstr(desc[x],n);
        if(p){
         printf("  %-8s   %-58s   %-5.2f   %-5.2f\n",codi[x],desc[x],dolar[x],reais[x]);
         l++;
        }               
     
     }if(l==1){
       printf("Produto nao encontrado!!!\n"); 
       }     
     system("pause");
}   
//-------------------------------------------------------------------------
void Mostra_Tabela(){
    
    system("cls");
    printf("Codigo",3);
    printf("Descricao  ");
    printf("                       Preco em Dolar");
    printf("     Preco em Real\n");
    for(x=0;x<2284;x++){
       printf("  %-8s   %-58s   %-5.2f   %-5.2f\n",codi[x],desc[x],dolar[x],reais[x]);
    }
system("pause");
}
//-----------------------------------------------------------------------
void Busca_bi(int l){
   int in=0,fim=2284,mid,pos=-1,a;                
   while(in<=fim && pos==-1){
      mid=(in+fim)/2;     
      a=atoi(codi[mid]);     
      if(a==l){
         pos=mid;
      }else{
         if(l<a){
           fim=mid-1;
         }else{
           in=mid+1;
          }
       }
   }
   if(pos!=-1){
      printf("\n  %-8s   %-58s   %-5.2f   %-5.2f\n",codi[pos],desc[pos],dolar[pos],reais[pos]);
      system("pause");
  }else{
       printf("Produto nao encontrado!!!\n");
       system("pause");
   } 
}
//------------------------------------------------------------
void Dolar_Reais(){
   for(x=0;x<2300;x++){
      reais[x]=dolar[x]*cotaDol;
   }
}
//-------------------------------------------------------------------
void Troca_Ordem (int i, int j){
     char tmpc[8],tmpde[58];
     float tmpdol,tmpreal;
     
     strcpy(tmpc,codi[i]);
     strcpy(codi[i],codi[j]);
     strcpy(codi[j],tmpc);
            
     strcpy(tmpde,desc[i]);
     strcpy(desc[i],desc[j]);
     strcpy(desc[j],tmpde);
            
     tmpdol=dolar[i];
     dolar[i]=dolar[j];
     dolar[j]=tmpdol;
     
     tmpreal=reais[i];
     reais[i]=reais[j];
     reais[j]=tmpreal;

}
//--------------------------------------------------------------------
void ClassDesc(){
    int q;
    system("cls");
    for(x=0;x<2299;x++){
      for(k=x+1;k<conta-7;k++){
         q=strcmp(desc[x],desc[k]);
         if(q==1){
            Troca_Ordem (x,k);
            }
       }
     }  
}
//-----------------------------------------------------------------
void Menu_Consulta(){
     int h=0,l=0,o=0,m=0,r;
     
     
      system("cls");
      printf("  Qual metodo de busca deseja realizar?\n");
      printf("  1- Por descricao\n");
      printf("  2- Por codigo\n");
      printf("  Insira um numero diferente de 1 e 2 para voltar para o menu\n ");
      printf("  Opcao: ");
      scanf("%i",&h);
      fflush(stdin);
      if(h==1){
         printf("\n  Digite o produto a ser consultado: ");
         gets(prod);
         m=strlen(prod);
           for (x=0;x<m;x++){
              prod[x]=toupper(prod[x]);
           }        
         Busca(prod);
      }else{
        if(h==2){
          ClassCod();
          printf("\n  Digite o codigo a ser consultado: ");   
          scanf("%d",&r);
          Busca_bi(r);
        }else{       
           Menu_Principal();
         }     
      }
}
//----------------------------------------------------------------
void ClassCod(){
    int q;
    system("cls");
    for(x=0;x<2299;x++){
      for(k=x+1;k<conta-7;k++){
         q=atoi(codi[x]);
         w=atoi(codi[k]);
         if(q>w){
            Troca_Ordem (x,k);
            }
       }
     }
}
//---------------------------------------------------------------------------
void Menu_Dolar() {
   cotaDol=0;
   system("cls");
   printf("\n  Insira a cotacao atual do Dolar: ");
   scanf("%f",&cotaDol);
   fflush(stdin);
   Dolar_Reais();
   Menu_Principal();
}
//----------------------------------------------------------------------------
void Menu_Principal() {
   while(y!=6){
     y=0;
     system("cls");
     printf("\n  Cotacao atual do dolar inserida: R$ %-5.2f\n",cotaDol);
     printf("  1- Inserir nova cotacao do Dolar\n");
     printf("  2- Consultas\n");
     printf("  3- Classificar por CODIGO\n");
     printf("  4- Classificar por DESCRICAO\n");
     printf("  5- Mostrar tabela completa\n");
     printf("  6- Sair\n");
     printf("  Opcao: ");
     scanf("%d",&y);
     fflush(stdin);
      switch(y){
        case 1: 
             Menu_Dolar();
             break;
        case 2: 
             Menu_Consulta();
             break;
        case 3: 
             ClassCod();
             break;
        case 4: 
             ClassDesc();
             break;     
        case 5: 
             Mostra_Tabela();
             break;
        case 6: 
             printf("\n  Voce escolheu sair\n");
             break;    
        default: 
               printf("Digite uma opcao valida\n");
                 system("pause");
     }
  }
}
//------------------------------------------------------------
void Tira_Ponto(){   
    for(x=0;x<conta-7;x++){
      y=56;                               
        while(desc[x][y]=='.'||desc[x][y]==' '){
           desc[x][y]='\0';
           y--;
        }
   }     
}
//-----------------------------------------------------------------
int main()
{

   FILE *arqu;

   char lin[200];
   char  codi[2300][8];
   char  desc[2300][58];
   float dolar[2300];
   char precoST[13];

   int conta=0,x,y=0,j,i,k,w,p; 
   float cotaDol,reais[2300];
   char prod[58];

   ler_arquivo();
   Menu_Dolar();
   Menu_Principal();
   system("pause");
   }