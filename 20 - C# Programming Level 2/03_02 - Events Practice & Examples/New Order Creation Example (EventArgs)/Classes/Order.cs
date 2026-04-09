using System;

namespace _03_02___Events_Practice_And_Examples.New_Order_Creation_Example__EventArgs_
{
    public class Order
    {
        public event EventHandler<OrderEventArgs> OrderCreated;

        public void Create(int orderId, double price, string email)
        {
            Console.WriteLine("New order created; All subscirbers will get notified\n");

            // alternative to: OrderCreated?.Ivoke(...)
            if (OrderCreated != null)
                OrderCreated(this, new OrderEventArgs(orderId, price, email));
        }
    }
}
