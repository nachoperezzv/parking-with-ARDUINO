# parking-with-ARDUINO
El código del repositorio busca resolver el problema propuesto para la actividad 1 de la práctica 2 de sensores, es decir, realizar la simulación de funcionamiento de la entrada y salida de un parking, teniendo además que añadir una comunicación serie entre Matlab y Arduino.

La resolución de la actividad se ha creado mediante el uso de distintas clases de C++ y con la implementación de interrupciones. Entre estas tendríamos:

-Barrier.cpp y barrier.h: en estos archivos se define la clase barrier, para así controlar a los leds que simulan las barreras del parking, y se implementan funciones para levantarlas, bajarlas u obtener su estado.

-LCD.cpp y LCD.h: archivos donde se configura la pantalla LCD utilizada y se pre-definen funciones para que esta dé los mensajes pedidos.

-Button.cpp y button.h: archivos donde se define la clase button, para controlar el estado del pulsador con muelle que se precisa en la actividad.

-Interruptions.cpp e interruptions.h: Se definen las interrupciones de entrada y salida, procesos donde se realiza la acción de subir y bajar barreras, dar mensajes por pantalla LCD y mantener comunicación vía serial con Matlab sobre el estado del botón y sensores ópticos. Estas interrupciones se lanzan en el caso de que se detecte presencia en los sensores ópticos. 

-Parking.cpp y parking.h: en estos archivos se realiza un set-up o inicialización de todas las clases definidas anteriormente, las cuales conforman nuestro parking y además define ciertas variables relevantes como el 	número máximo de coches la cantidad de coches que hay dentro. 

-Main.ino: este es el código principal de arduino que juntan las clases e interrupciones que se han definido antes, ordenando el proceso de ejecución y manteniendo una comunicación en serie con la interfaz diseñada para Matlab. Se utilizan las librerías creadas y en el código se definen los momentos en que se deben lanzar las interrupciones para entrada y salida. 
