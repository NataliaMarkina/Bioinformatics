using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4._1__Motif_Enumeration_Problem
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
                foreach (char c in str)
                {
                    get_words(ref words, str, length - 1, prefix + c);
                }
        }
        static bool IsValidMismatches(string original, string replica, int valid_mismatches)
        {
            int length = original.Length;
            int mismatches = 0;

            for (int i = 0; i < length; i++)
            {
                if (original[i] != replica[i])
                {
                    mismatches++;
                }

                if (mismatches > valid_mismatches)
                {
                    return false;
                }
            }

            return true;
        }
        static List<string> get_KDMotifs(string k_mer, int validMismatches)
        {
            string str = "AGCT";
            List<string> patterns = new List<string>();

            foreach (var word in get_words(str, k_mer.Length))
            {
                if (IsValidMismatches(word.ToString(), k_mer, validMismatches))
                {
                    patterns.Add(word.ToString());
                }
            }

            return patterns;
        }

        static List<string> MotifEnumeration(string[] dna, int k, int d)
        {
            List<string> patterns = new List<string>();

            foreach (string str in dna)
            {
                int length = str.Length;
                for (int i = 0; i<length - k + 1; i++)
                {
                    string kMer = str.Substring(i, k);

                    foreach (string pattern in get_KDMotifs(kMer, d))
                    {
                        int count = 0;
                        foreach (string substring in dna)
                        {
                            for (int j = 0; j<length - k + 1; j++)
                            {
                                if (IsValidMismatches(substring.Substring(j, k), pattern, d))
                                {
                                    count++;
                                    break;
                                }
}
                        }

                        if (count == dna.Length)
                        {
                            patterns.Add(pattern);
                        }
                    }
                }
            }

            return patterns;
        }

        static void Main(string[] args)
        {
            string[] strCoeff = Console.ReadLine().Split(' ');
            int k = int.Parse(strCoeff[0]);
            int d = int.Parse(strCoeff[1]);

            string buffer = "";

            while (true)
            {
                string s = Console.ReadLine();

                if (string.IsNullOrEmpty(s))
                    break;

                buffer += s + ' ';
            }

            string[] dna = buffer.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToArray();

            List<string> patterns = new List<string>();

            patterns = MotifEnumeration(dna, k, d);
            patterns = patterns.Distinct().ToList();

            Console.WriteLine(string.Join(" ", patterns));
            Console.ReadKey();
        }
    }
}
