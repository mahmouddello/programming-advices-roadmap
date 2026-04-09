using System;

namespace _03_02___Events_Practice_And_Examples.New_Order_Creation_Example__EventArgs_
{
    internal interface IOrderService
    {
        void Subscribe(Order order);

        void Unsubscribe(Order order);

        void HandleNewOrder(object sender, OrderEventArgs eventArgs);
    }
}
