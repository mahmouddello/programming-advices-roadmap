using System;

namespace _12____Mutable___Immutable_Types
{
    public class ImmutablePerson
    {
        public string Name { get; }
        public int Age { get; }


        public ImmutablePerson(string name, int age)
        {
            Name = name;
            Age = age;
        }
    }
}
