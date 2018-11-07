const int Vref = 5; //Tension de référence du CAN
const int potar = A0;// le potentiomètre, branché sur la broche analogique 0
const int fe = 10000; //fréquence d'échantillonnage 10kHz
int bitconv= pow(2,10); //Nombre de bit du convertisseur
int valeurLue; //variable pour stocker la valeur lue après conversion
float q=Vref/bitconv; //quantum
float tension; //on convertit cette valeur en une tension



 
void setup()
{
    //on se contente de démarrer la liaison série
    Serial.begin(9600);
}
 
void loop()
{
    //on convertit en nombre binaire la tension lue en sortie du potentiomètre
    valeurLue = analogRead(potar);
    
    //on traduit la valeur brute en tension (produit en croix)
    tension = valeurLue*q;

    //on affiche le quantum sur la liaison série
    Serial.print("quantum = ");
    Serial.println(q);
    
    //on affiche la valeur lue sur la liaison série
    Serial.print("valeurLue = ");
    Serial.println(valeurLue);
    
    //on affiche la tension calculée
    Serial.print("Tension = ");
    Serial.print(tension,2);
    Serial.println(" V");
    
    //on saute une ligne entre deux affichages
    Serial.println();
    //on attend une demi-seconde pour que l'affichage ne soit pas trop rapide
    delay(500);
}
