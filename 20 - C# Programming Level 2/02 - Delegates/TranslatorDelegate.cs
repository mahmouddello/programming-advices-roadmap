using System;

namespace _02___Events
{
    internal class TranslatorDelegate
    {
        delegate string Translator(string input);
        delegate string ChineseTranslator(string input, string accent);
        static void Main(string[] args)
        {
            Translator translator = new Translator(EnglishToFrench); // method name as argument: pointing to the method
            string result = translator.Invoke("Hi");
            // or translator("Hi") and it will work
            Console.WriteLine($"English --> French: {result}");

            // let's test the delegate with EnglishToChinese
            //translator = new ChineseTranslator(EnglishToChinese); // not allowed, signatre doesn't match

            ChineseTranslator chineseTranslator = new ChineseTranslator(EnglishToChinese);
            result = chineseTranslator.Invoke("Hey", "Mandarin");
            Console.WriteLine($"English --> Chinese (Mandarin): {result}");
        }

        static string EnglishToFrench(string message)
        {
            return "Bonjour!";
        }

        static string EnglishToSpanish(string message)
        {
            return "Hola!";
        }

        static string EnglishToGerman(string message)
        {
            return "Hallo!";
        }

        static string EnglishToChinese(string message, string accent)
        {
            return "nǐ hǎo!";
        }
    }
}
