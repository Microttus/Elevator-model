*************************************************************************************

	JM^2 Skylift

			
		Group 42


			This is the sourse code for operating the JM^2 skylift

				Authors:
				- Jørgen Borge
				- Martin Sauar Wad
				- Martin Økter

************************************************************************************



- 	Most needed librarys are included, but the stadard arduino 
	library are needed as well as LIquidCrystal and servo

-	The main_control.ino are to be opened in arduino IDE
	and uploaden to a Arduino MEGA 256

-	The code may be lanuched from a computer or keept at the ARDUINO
	and started on power up

-	If any physical conditions are to be changed most settings are to be 
	found in the first 4 list in main_control.ion with description

-	On lanche the cabin will initiate by coing down all the way to first 
	floor and stop. When doors open the elevator is ready

- 	The floors selector from inside the cabin can be choosen with button
	8-2, where 8 is 1st and 2 are 6th. 

-	The arrow button on each floor can be selected by choosing the right 
	floor with the potentionmeter and then either up arrow (buuton 1) or
	down arrow (button 0) can be pressed. 

-	While the steppper are runnning the queue wil be locked. The current
	floor of the elevator can be seen in the LCD together with the 
	current selected floor for the arrow button. 


-	If you have any question, send a mail to: martin.okter@uia.no



**********************************************************************************


				LINCENCCE


-	Any reuse of any of the sourse code or/and librarys are to be credited
	the authors in the code and any documentation
