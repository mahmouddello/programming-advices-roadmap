using System;

namespace _10___Misc
{

    public class OuterClass
    {
        private int outerVariable;

        public OuterClass(int outerVariable)
        {
            this.outerVariable = outerVariable;
        }

        public void OuterMethod()
        {
            Console.WriteLine("Outer method called.");
        }

        public class InnerClass
        {
            private int innerVariable;
            public InnerClass(int innerVariable)
            {
                this.innerVariable = innerVariable;
            }

            public void InnerMethod()
            {
                Console.WriteLine("Inner method called with innerVariable = " + innerVariable);
            }


            public void AccessOuterVariable(OuterClass outer)
            {
                Console.WriteLine("Accessing outerVariable from inner class: " + outer.outerVariable);
            }
        }
    }

    internal class NestedClasses
    {
        static void Main(string[] args)
        {
            // create an instance of OuterClass
            OuterClass outer1 = new OuterClass(42);

            // create an instance of InnerClass
            OuterClass.InnerClass inner1 = new OuterClass.InnerClass(100);

            // call methods on the instances
            outer1.OuterMethod(); // prints "Outer method called."
            inner1.InnerMethod(); // prints "Inner method called with innerVariable = 100"
            inner1.AccessOuterVariable(outer1); // prints "Accessing outerVariable from inner class: 42"
            Console.ReadKey();

        }
    }
}
