-------------------------------------
            VIDEO POKER 
-------------------------------------

## CLASSI


# CARTA 

Attributo:
-seme
-valore 


# MAZZO
// ci possono essere più mazzi in uno solo (per poter riutilizzare in più giochi)

Attributo:
- carte nel mazzo

Operazioni:
- Rimescola
- Pesca : carta

collegamenti: partoff -> CARTE 

# MANO
// collego la mano al mazzo in modo che al videopoker la mia mano pesca dal mazzo giusto

Attributo:

Operazioni:
- distribuisci 
- cambiacarta 
- valuta

Collegamento: 
1 -> partoff 5-> CARTE 
* -> 1 -> MAZZO


# VIDEOPOKER
// classe che contiene le leggi del gioco e il suo meccanismo

Attributo:
- credito
- vincite 

Operazioni:
- 

Collegamenti:
-> 1 -> MANO