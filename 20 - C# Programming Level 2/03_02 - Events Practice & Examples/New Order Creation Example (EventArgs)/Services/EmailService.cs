using System;

namespace _03_02___Events_Practice_And_Examples.New_Order_Creation_Example__EventArgs_
{
    internal class EmailService : IOrderService
    {
        public void Subscribe(Order order)
        {
            order.OrderCreated += HandleNewOrder;
        }

        public void Unsubscribe(Order order)
        {
            order.OrderCreated -= HandleNewOrder;
        }

        public void HandleNewOrder(object sender, OrderEventArgs eventArgs)
        {
            Console.WriteLine("------------- Email Service -------------");
            Console.WriteLine("Email Service Recieved a new order event");
            Console.WriteLine($"Order Id: {eventArgs.Id}");
            Console.WriteLine($"Order Price: {eventArgs.Price}");
            Console.WriteLine($"Client Email: {eventArgs.Email}");
            Console.WriteLine("-----------------------------------------\n");
        }
    }
}
