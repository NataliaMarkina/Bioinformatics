using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3._1__Cyclopeptide_Sequencing_Problem
{
    class Program
    {
        static Dictionary<char, int> AminoacidMass = new Dictionary<char, int>()
        {{'G', 57}, {'A', 71}, {'S', 87}, {'P', 97}, {'V', 99}, {'T', 101}, {'C', 103}, {'I', 113}, {'L', 113}, {'N', 114}, {'D', 115}, {'K', 128},
         { 'Q', 128}, {'E', 129}, {'M', 131}, {'H', 137}, {'F', 147}, {'R', 156}, {'Y', 163}, {'W', 186}};

        static int Mass(string peptide)
        {
            int mass = 0;
            for (int i = 0; i < peptide.Length; i++)
                mass += AminoacidMass[peptide[i]];
            return mass;
        }

        static List<string> Expand(List<string> peptides)
        {
            List<string> newPeptides = new List<string>();

            foreach (var peptide in peptides)
            {
                foreach (var key in AminoacidMass.Keys)
                {
                    newPeptides.Add(peptide + key);
                }
            }
            return newPeptides;
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

        static string LinearSpectrum(string peptide)
        {
            List<int> Linearspectrum = new List<int>();
            string subpeptide = " ";
            int mass = 0;

            if (peptide.Length == 1)
                return AminoacidMass[peptide[0]].ToString();

            Linearspectrum.Add(0);

            for (int i = 1; i < peptide.Length; i++)
            {
                for (int j = 0; j < peptide.Length; j++)
                {
                    if ((i + j) <= peptide.Length)
                    {
                        subpeptide = peptide.Substring(j, i);
                        Linearspectrum.Add(Mass(subpeptide));
                    }
                }
            }

            Linearspectrum.Add(Mass(peptide));

            Linearspectrum.Sort();
            return string.Join(" ", Linearspectrum);
        }

        static bool Consistent(string peptide, string spectrum)
        {
            List<string> SpecMass = spectrum.Split(' ').ToList();
            List<string> PeptideMass = LinearSpectrum(peptide).Split(' ').ToList();

            foreach (var mass in PeptideMass)
            {
                if (SpecMass.Contains(mass) != true)
                {
                    return false;
                }
            }
            return true;
        }

        static int ParentMass(string spectrum)
        {
            int parentMass = int.Parse(spectrum.Split(' ').Last());
            return parentMass;
        }

        static List<string> CyclopeptideSequencing(string Spectrum)
        {
            List<string> Peptides = new List<string>() { "" };
            List<string> PeptideOutput = new List<string>();

            while (Peptides.Count > 0)
            {
                Peptides = Expand(Peptides);
                List<string> PeptidesExemple = new List<string>(Peptides);
                foreach (var Peptide in PeptidesExemple)
                {
                    if (Mass(Peptide) == ParentMass(Spectrum))
                    {
                        if (CycloSpectrum(Peptide) == Spectrum)
                            PeptideOutput.Add(Peptide);
                        Peptides.Remove(Peptide);
                    }
                    else if (Consistent(Peptide, Spectrum) != true)
                    {
                        Peptides.Remove(Peptide);
                    }
                }
            }
            return PeptideOutput;
        }

        static void Main(string[] args)
        {
            string Spectrum = Console.ReadLine();

            List<string> PeptideOutput = new List<string>();
            PeptideOutput = CyclopeptideSequencing(Spectrum);

            List<string> MassOutput = new List<string>();

            foreach (var peptide in PeptideOutput)
            {
                List<string> mass = new List<string>();
                foreach (var i in peptide)
                {
                    mass.Add(AminoacidMass[i].ToString());
                }

                MassOutput.Add(string.Join("-", mass));
            }

            Console.WriteLine(string.Join(" ", MassOutput.Distinct()));
        }
    }
}