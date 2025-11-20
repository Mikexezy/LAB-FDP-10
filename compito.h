const int MAX_FILE = 26;
const int MAX_POSTI_FILA = 9;

struct Posto{
    bool disponibilità = true;
    Posto* next = nullptr;
};
typedef Posto** Sala;

class Cinema{
    private:
        char nome[26]; 
        Sala sala;
    
    public:
        // n = numero file
        // p = numero posti per fila
        // s = nome cinema
        Cinema(int n, int p, const char* s);

        //l = lettera della fila
        //j = numero del posto
        bool prenota(char l, int j);

        //l = lettera della fila
        //j = numero del posto
        bool cancella(char l, int j);

        void stampa();
};