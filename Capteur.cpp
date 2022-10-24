# Capteur de vitesse

int analogPin = 3;    

int val = 0,compteur = 0, iMemoire = 0, iter=0; // variable de type int pour stocker la valeur de la mesure
float temps1, temps2, vitesse, sec, temps_final;
void setup()
{
  Serial.begin(9600);          //  initialisation de la connexion série
// IMPORTANT : la fenêtre terminal côté PC doit être réglée sur la même valeur.
}

void loop()
{  
  // lit la valeur de la tension analogique présente sur la broche
  val = analogRead(analogPin);    
    
  if ((val > 500) && (iMemoire == 0))                                                               
  {  
    compteur++,
    iMemoire = 1;
    
    if (iter==0)
    {
      iter=1,
      temps1=millis();
    }
    else 
    {
      temps2=millis(),
      temps_final=(temps2-temps1),
      Serial.println(compteur),
      iter=0,
      sec=(temps_final/1000),
      vitesse=60/sec,
      Serial.println(sec),
      Serial.println(vitesse);
    }         
  } 
  else if ((val < 500) && (iMemoire == 1))  
  { 
     iMemoire = 0;
  }          
   
}
