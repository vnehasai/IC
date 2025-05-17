# ICS_CP_b23cm1047_cs1076_ee1029_ci1021
ic_project
ic project description:



 This is our project for ATM.


 Firstly, it asks account number of the user

 
 If the account number is not present, It asks the user "Do you want to create a new account? 1.YES 2.NO"
 a) If the user gives input as 1, it asks the user to enter the account number and then password. It asks the user to enter the pin number again for 
 confirmation.
 If the entered pin number is correct, the user is asked to enter his/her account holder name. The output is given as "ACCOUNT CREATED THANK YOU VISIT 
 AGAIN" and then the code terminates.
 If the entered pin number is not matching with previously given pin number, it gives output as "The password you have entered before and now are not 
 matching TRY AGAIN" and then the code terminates.
 b) If the user gives input as 2, It gives the output as "THANK YOU VISIT AGAIN" and then the code terminates.

 
 If the account is already present, it asks to enter the pin number.
 If the pin number that the user had given is incorrect, it gives output as "INCORRECT PASSWORD TRY AGAIN"
 If the pin number that the user had given is correct, it displays 5 options namely
 1)check balance
 2)cash withdrawl
 3)cash deposit
 4)change pin number
 5)transfer fund

 
 User have to select one of the options

 
 When user gives input as 1, check balance option is selected. Then the current balance of the account present is given as output and
 then the code terminates.

 
 When user gives input as 2, cash withdrawl option is selected. We ask the user to enter the amount that he/she wants to withdraw,
 if the user gives input amount more than his/her balance, it shows "INSUFFICIENT BALANCE" and the code terminates.
 if the input amount is within the balance, it gives output as "Amount withdrawn successfully" and the updated current balance of that account is shown 
 after transaction and the code terminates.

 
 When user gives input as 3, cash deposit option is selected.  We ask the user to enter the amount that he/she wants to deposit,
 User have to give the input amount that is to be deposited. Then the output is given as "Amount deposited successfully" and the updated current balance of 
 that account is shown after transaction and the code terminates.

 
 When user gives input as 4, change pin number option is selected. It asks the user to enter the pin number once again for more authentication. If the given 
 pin number matches with the actual pin no, it asks to enter new pin no. Then the user is supposed to enter new pin number. The user is again asked 
 to enter the new pin number for security reasons. 
 a)Once the entered pin number matches with the previously given new pin number,the pin number is changed and output is given as "PIN NUMBER CHANGED SUCCESSFULLY" and the code terminates
 b)If the entered pin number does not match with the previously given new pin number output is given as "The pin numbers you entered are not the same CHECK 
 AGAIN THANK YOU" and the code terminates


 When user gives input as 5, transfer fund option is selected. It asks to enter the pin number again for more authentication
 A) If the entered pin number is correct, it asks to enter the account number to which the user wants to transfer money. It asks to enter the account number 
    again for more authentication.
    
    a)If both the account numbers match and if the entered account number exists, it asks to enter the amount that the user wants to transfer. It asks to 
    enter the transaction amount again for confirmation. If the given transaction amount matches with the previously given transaction amount, The code 
    shows the current balance of user's account after transaction and shows "AMOUNT TRANSFERRED SUCCESSFULLY". If the given transaction amount does not 
    match with the previously given transaction amount, it shows "The amount you entered previously and now are not same TRY AGAIN" 
    
    b)If both the account numbers does not match, it shows "The account number you gave now is not same as before"
    
    c)If the entered account number does not exist, it shows "Account not found CHECK AGAIN"
    
 B) If the entered pin number is incorrect, It shows "INCORRECT PIN NUMBER TRY AGAIN" and then the code terminates


THIS IS THE END OF OUR IC PROJECT...
    THANK YOU
    HAPPY CODING😊
