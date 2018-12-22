using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4._2__Median_String_Problem
{
    class Program
    {
        static List<string> get_words(string str, int length)
        {
            List<string> words = new List<string>((int)Math.Pow(4, length));

            get_words(ref words, str, length, "");

            return words;
        }
        static void get_words(ref List<string> words, string str, int length, string prefix)
        {
            if (length == 0)
            {
                words.Add(prefix);
            }
            else
            {
                foreach (char c in str)
                {
                    get_words(ref words, str, length - 1, prefix + c);
                }
            }
        }
        static int hamming(string a, string b)
        {
            int count = 0;
            int length = a.Length;

            for (int i = 0; i < length; i++)
            {
                if (a[i] != b[i])
                {
                    count++;
                }
            }

            return count;
        }
        static int dist_min(string pattern, string text)
        {
            int lengthText = text.Length;
            int lengthPattern = pattern.Length;

            List<int> dist = new List<int>();

            for (int i = 0; i < lengthText - lengthPattern + 1; i++)
            {
                dist.Add(hamming(pattern, text.Substring(i, lengthPattern)));
            }

            return dist.Min();
        }
        static int DDNA(string pattern, string[] dna)
        {
            int sum = 0;

            foreach (string dnai in dna)
            {
                sum += dist_min(pattern, dnai);
            }

            return sum;
        }
        static string MedianString(string[] dna, int k)
        {
            int distance = int.MaxValue;
            string str = "";

            List<string> k_mers = get_words("AGCT", k);

            foreach (string k_mer in k_mers)
            {
                if (distance > DDNA(k_mer, dna))
                {
                    distance = DDNA(k_mer, dna);
                    str = k_mer;
                }
            }

            return str;
        }
        static void Main(string[] args)
        {
            int k = int.Parse(Console.ReadLine());

            string buffer = "";
            while (true)
            {
                string str = Console.ReadLine();

                if (string.IsNullOrEmpty(str))
                    break;

                buffer += str + ' ';
            }

            string[] dna = buffer.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            Console.WriteLine(MedianString(dna, k));
            Console.ReadKey();
        }
    }
}
