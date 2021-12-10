# Car-Rental-System
 A C++ based project wherein concepts of object oriented programming such as inheritance,data abstraction,  polymorphism, threading are implemented.
 
## Project Workings
 The base idea of this project is to provide the service to a user in two ways :-<br />
 • User may rent a car from a given list of different car models avialable for renting (say user 1).<br />
 • User may provide his/her car for renting and get paid for each ride of the car (say user 2).<br /><br/>
 ![alt text](https://github.com/Shubham999-del/Car-Rental-System/blob/master/user_interface.png) <br/>
 The project has two modes in which a user can work with it :-
 1) **User 1** <br/>
    • User can view the car details. (available cars and their prices) <br/><br/>
    ![alt text](https://github.com/Shubham999-del/Car-Rental-System/blob/master/car_prices.png) <br/>
    • User can rent a car from the garage. <br/> <br/>
    As the user rents a car, he/she is charged per hour of car usage. To account for the time for which the user has been using the rented car, a unique thread is assigned to the user that works in the background and is accounting for the usage time. As soon as the time gievn by the user expires the thread expires and the ride is ended. An invoice bill gets created for the user showing all the necessary details about the ride and the final amount to be paid by the user<br/>
    
    

 2) **User 2** <br/>
    • User can view the prices for the floated car models.<br/>![admin_option](https://user-images.githubusercontent.com/53961643/145581555-9ac0ae3c-62c0-4c2a-a106-199cc932c753.png)

    • User can provide their car for rental services.<br/>
    • User can view his earnings .<br/>
    • User can view the status of the rented car .<br/><br/>
    
    ![alt text](https://github.com/Shubham999-del/Car-Rental-System/blob/master/user2_choices.png)<br/><br/>
    
## The Admin
 The admin is the authority that maintains the database of the system as well as set the final prices of the cars present in the system.
 Admin will have to go through a login system to gain access to the database of the system. <br/><br/>
  ![alt text](https://github.com/Shubham999-del/Car-Rental-System/blob/master/admin_login.png)<br/>

 The admin of the systemis the one that has the following access to the system :- <br/>
    • Admin will have the final say in setting the rental prices of cars as per car models. <br/>
    • Admin can modify the rental rate of any car as per the present condition and performance of the car. <br/>
    • Admin will get the requests from either type of users. <br/>
    ![alt text](https://github.com/Shubham999-del/Car-Rental-System/blob/master/admin_option.png)<br/><br/>


## Files data
 | Files | Data |
 | :--: | :--:|
 |cardetails.txt| Gives the file prices and count of its customers for renting|
 |carsdata.txt| Gives info about every car and its data members |
 |membersdata.txt| Gives info of every user2 and its data members | <br/><br/>
 
 
## Code
| .cpp file | Working |
| :--: | :--:|
| main.cpp | the main executable file containing all the structure of the project|

 
