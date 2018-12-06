using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3._2__Cyclopeptide_Scoring_Problem
{
    class Program
    {
        static Dictionary<char, int> AminoacidMass = new Dictionary<char, int>()
        { { 'G',57 },{ 'A',71 },{ 'S',87 },{ 'P',97 },{ 'V',99 },{ 'T',101 },{ 'C',103 },{ 'I',113 },{ 'L',113 },{ 'N',114 },
        { 'D',115 },{ 'K',128 },{ 'Q',128 },{ 'E',129 },{ 'M',131 },{ 'H',137 },{ 'F',147 },{ 'R',156 },{ 'Y',163 },{ 'W',186 } };

        static int Mass(string peptide)
        {
            int mass = 0;
            for (int i = 0; i < peptide.Length; i++)
                mass += AminoacidMass[peptide[i]];
            return mass;
        }

        static string CycloSpectrum(string peptide)
        {
            List<int> Cyclospectrum = new List<int>();
            string subpeptide = " ";
            int mass = 0;

            Cyclospectrum.Add(0);

            for (int i = 1; i < peptide.Length; i++)
            {
                for (int j = 0; j < peptide.Length; j++)
                {
                    if ((i + j) <= peptide.Length)
                        subpeptide = peptide.Substring(j, i);
                    else
                        subpeptide = peptide.Substring(j) + peptide.Substring(0, i + j - peptide.Length);

                    Cyclospectrum.Add(Mass(subpeptide));
                }
            }

            Cyclospectrum.Add(Mass(peptide));

            Cyclospectrum.Sort();
            return string.Join(" ", Cyclospectrum);
        }

        static int Score(string peptide, string spectrum)
        {
            List<string> peptideMass = CycloSpectrum(peptide).Split(' ').ToList();
            List<string> spectrumMass = spectrum.Split(' ').ToList();

            int score = 0;

            foreach (var mass in peptideMass)
            {
                if (spectrumMass.Contains(mass))
                {
                    spectrumMass.Remove(mass);
                    score++;
                }
            }

            return score;
        }
        static void Main(string[] args)
        {
            string Peptide = Console.ReadLine();
            string Spectrum = Console.ReadLine();

            Console.WriteLine(Score(Peptide, Spectrum));
        }
    }
}
