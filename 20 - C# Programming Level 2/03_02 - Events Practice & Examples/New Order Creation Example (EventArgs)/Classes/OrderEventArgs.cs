using System;

namespace _03_02___Events_Practice_And_Examples.New_Order_Creation_Example__EventArgs_
{
    public class OrderEventArgs : EventArgs
    {
        public int Id { get; }
        public double Price { get; }
        public string Email { get; }

        public OrderEventArgs(int id, double price, string email)
        {
            Id = id;
            Price = price;
            Email = email;
        }
    }
}
