#include<iostream>
#include<cstring>

#include"compito.h"

using namespace std;

typedef Posto** Sala;

// n = numero file
// p = numero posti per fila
// s = nome cinema
Cinema::Cinema(int n, int p, const char* s){
    if(n <= MAX_FILE && p <= MAX_POSTI_FILA){
        strcpy(this->nome, s);
                
        sala = new Posto*[n];

        for(int i=0; i < n; i++){
            sala[i] = new Posto;

            Posto* temp = sala[i];

            for(int k=1; k < p; k++){
                temp->next = new Posto;
                temp = temp->next;
            }
        }
    }
};

//l = lettera della fila
//j = numero del posto
bool Cinema::prenota(char l, int j){
    if(l <= ('A' + MAX_FILE) && j <= MAX_POSTI_FILA){
        for(char f='A'; f <= l; f++){
            if(l == f){
                Posto* fila = sala[f-'A'];

                for(int p=1; p <= j; p++){
                    if(fila->next != nullptr && p < j){
                        fila = fila->next;
                    }else if(fila->next == nullptr && p < j){
                        return false;
                    }
                }

                if(fila->disponibilità){
                    fila->disponibilità = false;
                    return true;
                }

                return false;
            }
        }

    }

    return false;
};

//l = lettera della fila
//j = numero del posto
bool Cinema::cancella(char l, int j){
    if(l <= ('A' + MAX_FILE) && j <= MAX_POSTI_FILA){

        for(char f='A'; f <= l; f++){
            if(l == f){
                Posto* fila = sala[f-'A'];

                for(int p=1; p <= j; p++){
                    if(fila->next != nullptr && p < j){
                        fila = fila->next;
                    }else if(fila->next == nullptr && p < j){
                        return false;
                    }
                }

                if(fila->disponibilità == false){
                    fila->disponibilità = true;
                    return true;
                }

                return false;
            }
        }    
    }
    return false;
};

void Cinema::stampa(){
    if(sala != nullptr){
        cout<<"Nome del cinema: "<<nome<<endl;
        Posto* fila = sala[0];
        int posto = 1;

        if(fila != nullptr){
            cout<<" "<<posto;
            while(fila->next != nullptr){
                fila = fila->next;
                posto++;
                cout<<posto;
            }
            cout<<endl;
        }

        for(char f='A'; f < ('A' + MAX_FILE); f++){
            fila = sala[f-'A'];
            if(fila != nullptr){
                cout<<f;

                for(int p=0; p<posto; p++){
                    if(fila->disponibilità == false){
                        cout<<"*";
                    }else{
                        cout<<" ";
                    }

                    if(fila->next != nullptr){
                        fila = fila->next;
                    }
                }     
                cout<<endl;
            }else{
                break;
            }
        }
    }
};
