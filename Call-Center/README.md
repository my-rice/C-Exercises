# Call-Center
## Exercise
Write a program that simulates the queuing of customers of a call center of a telephone company. Customers can choose between 3 types of requests:

1. Information on rate plans
2. Information on telephone traffic
3. Information on promotions

Each customer is waiting in an appropriate queue (rates, traffic, promotions) all with the same priority. Each queue can queue up to 20 customers and is served by a single operator.
The data relating to each customer are as follows:

• Telephone number (A 10-character string).
• Customer Surname (A string of 20 characters).
• Customer Name (A string of 20 characters).

The program must offer the following features:

• Queue a customer in the appropriate queue if there is space (already provided).
• Serve a customer if the operator is free.
• Free an operator.
• Print the next customers to be served for each queue on the screen.

For the realization of the functionalities, the student has at his disposal:
• the design of the entire application, already defined in terms of files and prototypes of the functions to be implemented;
• all the functions for managing the queue, except for some, already provided to the student which must be used without making any changes to the prototypes or their implementation. Missing functions must be implemented by the student.

## Given files
The files provided to the student are as follows:
• info.h (not to be changed)
Contains the definition of the TInfo type and the prototypes of the functions for its management

• info.c (not to be changed)
Contains the implementation of the functions for the management of TInfo

• queue.h (not to be changed)
Contains the definition of the TQueue type and the prototypes of the functions for the management of TQueue (standard functions)

• queue.c (to be completed)
Contains the implementation of the functions for the management of TQueue (standard functions)

• menu.h (not to be changed)
Contains prototypes of user interface functions.

• menu.c (not to be changed)
Contains the implementation of the user interface functions.

• customer_management.h (not to be modified)
Contains the prototypes of the functions required by the application:
> int queue_cliente (TQueue * rates, TQueue * traffic, TQueue * promotions);

• The function returns 1 if the customer is queued, 0 if there is no space in the queue of interest. (The function is already provided)
> int servi_clienti (TQueue * rates, TQueue * traffic, TQueue * promotions, bool * op_free_tariffs, bool * op_free_traffic, bool * op_free_promotions);

• The function checks, for each queue, if the operator is free. In the case of a free operator, the next customer waiting in the appropriate queue is served. It is possible to serve several customers queued in different queues at the same time. If the customer is served, the operator variable is set to false. The function returns 1 if only one customer is served, 2 if two are served, 3 if three are served, 0 if no customers are served.
> int free_operator (bool * op_free_tates, bool * op_free_traffic, bool * op_free_promotions);

• The function initially requires the operator to be released, if the operator is busy it sets the value of the variable relating to that operator to true and returns 1, if the operator is free it returns 0.
> void print_next_customers (TQueue rates, TQueue traffic, TQueue promotions);

• The function prints the next customer to be served for each queue, if there are no customers to be served, an appropriate empty queue message is printed.

• customer_management.c (to be completed)
Contains the implementation of the functions required by the application

• callcenter.c (to be completed)
Contains the main of the program.