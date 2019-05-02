#include <stdio.h>
#include <stdbool.h>   
    void Estacao(int a, int d, int m){
      int x, res;
      if (m > 2){
           m = m - 2;
           x = 8;
       }else{
           a = a - 1;
           x = 13;
       }
       res = (x + d + 2 * m + ((7 * m) / 12) + a % 7 + a / 4 % 7 - (3 * (1 + a / 100)) / 4 % 7) % 7;
       if (res == 0) printf("Sabado");
       else if (res == 1) printf("Domingo");
           else if (res == 2) printf("Segunda");
               else if (res == 3) printf("Terça");
                   else if (res == 4) printf("Quarta");
                       else if (res == 5) printf("Quinta");
                           else if (res == 6) printf("Sexta");
    }

	void EquinocioPrimavera(int resp3, int a, int d, int m){
		if(resp3 == 1){
            d = 22;
            m = 9;
			printf("Em %d o Equinócio de primavera cairá em um(a): ", a);
            Estacao(a, d, m);
          }else if(resp3 == 2){
            d = 20;
            m = 3;
			printf("Em %d o Equinócio de primavera cairá em um(a): ", a);
            Estacao(a, d, m);
          }
           printf("\n");
           
	}

	void EquinocioOutono(int resp2, int a, int d, int m){
		if(resp2 == 1){
            d = 20;
            m = 3;
			printf("Em %d o Equinócio de primavera (%d/%d) cairá em um(a): ", a, d, m);
            Estacao(a, d, m);
          }else if(resp2 == 2){
            d = 22;
            m = 9;
			printf("Em %d o Equinócio de primavera (%d/%d) cairá em um(a): ", a, d, m);
            Estacao(a, d, m);
          }
		   printf("\n");
          
	}

	int AnoBi(int ano){
		int bi= 0;
        if (ano%100 == 0){
          ano = ano/100;
        }
        if(ano%4 == 0){
            bi = 1;
        }else {
             
            bi = 0;
        }
		return bi; 
	}

	int Menu(int resp){
		
		
        printf("Escolha uma opção:\n");
        printf("\n");
        printf("1 - Data especifica\n");
        printf("2 - Pascoa (Paixão de Cristo incluso e Quarta de Cinzas)\n"); //Domingo  com paixão de cristo na sexta
        //printf("3 - Quarta feira de cinzas\n"); // Pascoa - 47
        printf("3 - Natal\n"); // 25/12
        printf("4 - Confraternizaçao Universal\n"); // 01/01
        printf("5 - Aniversario de Sao Bernardo do Campo\n"); // 20 de agosto
        printf("6 - Dias de Lua Cheia\n"); // a cada 29 dias
        printf("7 - Entrada das estaçoes\n"); 
        printf("8 - Equinocio de primavera\n");
        printf("9 - Equinocio de outono\n");
        printf("\n");
        scanf("%d", &resp);
        printf("\n");

		return resp;
	}
	void DataEspecifica(int a, int d, int m){
		printf("Dia: "); 
		scanf("%d",&d);
		printf("Mes: ");
		scanf("%d", &m);
		printf("Esse dia cairá em um(a): ");
		Estacao(a, d, m);
	}
	void Pascoa(int a, int d, int m){
		int y = a;
		int g=0, c=0, t=0, z=0, e=0, n=0, p=0, QC;
          g =(y%19)+1;
          c =(y/100)+1;
          t =((3*c)/4)-12;
          z =(((8*c)+5)/25)-5;
          e =((11*g) + 20 + z - t)%30;
            if ((e == 25 && g > 11) || (e == 24)){
                  e++;
            }
          
          n =(44-e);
            if (n<21){
              n = n+30;  
            }
          
          p =((5*y)/4)-(t+10);
          n =(n+7)-((p+n)%7);
          int w;
          if(n>31){
                
                d = n - 31;
                QC = d;
                m = 4;
                w = n-33;
                if(w < 1){
                  printf("Paixao de Cristo: %d de marco de %d, Sexta\n", 32+w, y);
                }else{
                  printf("Paixao de Cristo: %d de abril de %d, Sexta\n", (n-33), y);
                }
                printf("Pascoa: %d de abril de %d, Domingo\n", (n-31), y);
                
                
            }else{
                
                printf("Paixao de Cristo: %d de marco de %d, Sexta\n", n-3, y);
                printf("Pascoa: %d de marco de %d, Domingo\n", n, y);
                d = n;
                QC = d;
                m = 3;
            }
            printf("\n");
            int DQC = 1;
            while(DQC < 47){
              QC = QC - 1;
              DQC++;
              if(QC == 0 && m == 4){
                m = 3;
                QC = 31;
              }else if(QC == 0 && m == 3){
                m = 2;
                QC = 28;
              }
            }
            if(m == 3){
              printf("Quarta de Cinzas: %d março de %d\n ", QC, a);
            }else if(m == 2){
              printf("Quarta de Cinzas: %d fevereiro de %d\n ", QC, a);
            }
            printf("Quarta de Cinzas cairá em um(a): ");
            d = QC;
            Estacao(a, d, m);

	}
	void Natal(int a, int d, int m){
		d = 25;
        m = 12;
        printf("Em %d o Natal (%d/%d) cairá em um(a): ", a, d, m);
        Estacao(a, d, m);

	}
	void AnoNovo(int a, int d, int m){
		d = 01;
        m = 01;
        printf("Em %d o Ano Novo (%d/%d) cairá em um(a): ", a, d, m);
        Estacao(a, d, m);
	}
	void AniverSBC(int a, int d, int m){
		d = 20;
        m = 8;
        printf("Em %d o Aniversário de SBC cairá em um(a): ", a);
        Estacao(a, d, m);
	}
	void LuaCheia(int a, int d, int m, int bi){
		//Lua cheia a cada 29,5 dias
          int temporario;
		  temporario = a;
            a = a%1000;
            if(a % 100 == 0){
              a = 0;
            }
          //dia 1 e mes 1 pra sempre pegar o primeiro dia do ano
          d = 1;
          m= 1;
          int i=0;
          int R = 0, VALOR = 0;
          int dif, dif2;
          while(VALOR < 6 || VALOR > 7){
            //Isso calcula a lua cheia
            R = (a + 2) * 11 + d + m; 
            VALOR = R % 31;
            d++;
          }

          printf("%d / %d / %d está no periodo de Lua Cheia\n", d-1, m, a);
		  Estacao(temporario, d , m);
		  printf("\n");
          bool gambiarra= false;
          d = (d - 1) + 29.5;
          
          while(m < 12){
            if(gambiarra==true){
              d++;
              gambiarra=false;
            }else{
              gambiarra=true;
            }
			if(m == 1 || m == 3|| m == 5|| m ==7|| m == 8 || m == 10|| m == 12){
 
              if(d > 31){

                d-=31;
                
                if(m + 1 == 2 && bi == 0 && d > 28){
                  d-=28;
                  m = 2;
                }else if(m + 1 == 2 && bi == 1 && d > 29){
                  d-=29;
                  m = 2;
                }
                m++;
            }
              
            }else if(m == 2 && bi == 1){

              if(d > 29){
                
                d-=29;
                
                m++;
              }
            }else if(m == 2 && bi == 0){

              if(d > 28){
                d-=28;
                
                
                m++;
              }
            }else if(m == 4 || m == 6 || m == 9 || m == 11){
            
              if(d > 30){
                
                d-=30;
                
                m++;
              }
             }

            printf("%d / %d / %d está no periodo de Lua Cheia\n", d, m, a);
			if(m < 3){
				d = (d -1) + 29.5;
			}else{
				d = d + 29.5;
			}

			Estacao(temporario, d , m);
			printf("\n");
          }
	}

	void EstacaoAno(int resp4, int a){
		if(resp4 == 1){
             /*

            Verão: 21 junho até 20 setembro
            Outono: 21 setembro até 20 dezembro
            Inverno: 21 dezembro até 20 março
            Primavera: 21 março até 20 junho
            
            */
            printf("Verão vai começar em um(a): "); 
            Estacao(a, 21, 6);
            printf("\n");
            printf("Verão irá terminar em um(a): ");
            Estacao(a, 20, 9);
            printf("\n");

            printf("\n");
            printf("Outono vai começar em um(a): "); 
            Estacao(a, 21, 9);
            printf("\n");
            printf("Outono irá terminar em um(a): ");
            Estacao(a, 20, 12);
            printf("\n");

            printf("\n");
            printf("Inverno vai começar em um(a): "); 
            Estacao(a, 21, 12);
            printf("\n");
            printf("Inverno irá terminar em um(a): ");
            Estacao(a, 20, 3);
            printf("\n");

            printf("\n");
            printf("Primavera vai começar em um(a): "); 
            Estacao(a, 21, 3);
            printf("\n");
            printf("Primaver irá terminar em um(a): ");
            Estacao(a, 20, 6);
            printf("\n");
           

          }

          if(resp4 ==2){
            /*

            Verão: 21 dezembro até 20 março
            Outono: 21 março até 20 junho
            Inverno: 21 junho até 20 setembro
            Primavera: 21 setembro até 20 dezembro
            
            */
            printf("Verão vai começar em um(a): "); 
            Estacao(a, 21, 12);
            printf("\n");
            printf("Verão irá terminar em um(a): ");
            Estacao(a, 20, 3);
            printf("\n");

            printf("\n");
            printf("Outono vai começar em um(a): "); 
            Estacao(a, 21, 3);
            printf("\n");
            printf("Outono irá terminar em um(a): ");
            Estacao(a, 20, 6);
            printf("\n");

            printf("\n");
            printf("Inverno vai começar em um(a): "); 
            Estacao(a, 21, 6);
            printf("\n");
            printf("Inverno irá terminar em um(a): ");
            Estacao(a, 20, 9);
            printf("\n");

            printf("\n");
            printf("Primavera vai começar em um(a): "); 
            Estacao(a, 21, 9);
            printf("\n");
            printf("Primaver irá terminar em um(a): ");
            Estacao(a, 20, 12);
            printf("\n");

          }
	}
    int main(void)
    {
        int d, m, a, res, x, resp, resp2, resp3, resp4, bi, CC;
		printf("Escolha um ano: ");
        scanf("%d", &a); 
        printf("\n");
		CC = 1;
		while(CC == 1){
			resp = Menu(resp);
        	bi = AnoBi(a); 

			if(resp == 1){

				DataEspecifica(a, d, m);
				printf("\n");

			}else if(resp == 2){

				Pascoa(a, d, m);
				printf("\n");

			}else if(resp == 3){

				Natal(a, d, m);
				printf("\n");

			}else if(resp == 4){

				AnoNovo(a, d, m);
				printf("\n");

			}else if(resp == 5){

				AniverSBC(a, d, m);
				printf("\n");

			}else if(resp == 6){

				LuaCheia(a, d, m, bi);
				printf("\n");

			}else if(resp == 7){

				printf("\n");
				printf("Escolha uma opção:\n");
				printf("\n");
				printf("[1] - Hemisfério Norte\n");
				printf("[2] - Hemisfério Sul\n");
				printf("\n");
				scanf("%d", &resp4);
				
				EstacaoAno(resp4, a);
				printf("\n");

			}else if(resp == 8){
				/*
				No Brasil, que está localizado no Hemisfério Sul, o equinócio de primavera normalmente ocorre entre os dias 21 e 23 de setembro (variando anualmente).

				Hemisfério Norte o equinócio de Primavera acontece normalmente entre os dias 20 e 21 de março.
				*/
				
				printf("\n");
				printf("Escolha uma opção:\n");
				printf("\n");
				printf("[1] - Hemisfério Norte\n");
				printf("[2] - Hemisfério Sul\n");
				printf("\n");
				scanf("%d", &resp2);

				EquinocioOutono(resp2, a, d, m);
				printf("\n");
			
			}else if(resp == 9){

				printf("\n");
				printf("Escolha uma opção:\n");
				printf("\n");
				printf("[1] - Hemisfério Norte\n");
				printf("[2] - Hemisfério Sul\n");
				printf("\n");
				scanf("%d", &resp3);

				EquinocioPrimavera(resp3, a, d, m);
				printf("\n");
			}
		printf("\n");
		printf("Deseja pesquisar mais datas desse ano? [1] Sim / [0] Não.");
		printf("\n");
		scanf("%d", &CC);
	}
		

       
       return 0;
  }