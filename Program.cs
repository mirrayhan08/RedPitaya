using System;
using System.IO;
using LumenWorks.Framework.IO.Csv;

namespace RedPitaya
{
    class Program
    {
        static void Main(string[] args)
        {
            var csvTable = new System.Data.DataTable();
            using (var csvReader = new CsvReader(new StreamReader(System.IO.File.OpenRead(@"C:\D\MS Study\3rd Semester\AIS\RedPitaya\ml\human.csv")), true))
            {
                csvTable.Load(csvReader);
            }
        }
    }
}
