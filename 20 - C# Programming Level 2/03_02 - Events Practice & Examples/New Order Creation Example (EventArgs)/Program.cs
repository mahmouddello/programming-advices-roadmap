using _03_02___Events_Practice_And_Examples.New_Order_Creation_Example__EventArgs_.Services;
using System;

namespace _03_02___Events_Practice_And_Examples.New_Order_Creation_Example__EventArgs_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Order order = new Order();

            EmailService emailService = new EmailService();
            SmsService smsService = new SmsService();
            ShippingService shippingService = new ShippingService();

            emailService.Subscribe(order);
            smsService.Subscribe(order);
            shippingService.Subscribe(order);

            order.Create(10, 250, "mahmod@google.com");
        }
    }
}
