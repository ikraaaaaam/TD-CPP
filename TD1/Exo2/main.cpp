#include "Complex2D.h"

int main() {
    Complex2D c1;                   
    Complex2D c2(3.0, 4.0);         
    Complex2D c3(5.0);              
    Complex2D c4(c2);               

    
    c1.afficher();                   
    c2.afficher();                   
    c3.afficher();                   
    c4.afficher();                   

    
    Complex2D c5 = c2 + c3;
    Complex2D c6 = c2 - c3;
    Complex2D c7 = c2 * c3;
    Complex2D c8 = c2 / c3;

    
    c5.afficher();  
    c6.afficher();  
    c7.afficher();  
    c8.afficher();  

    return 0;
}
