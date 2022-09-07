
using ProblemSolving;

void CheckingStringEquals()
{
    string s1 = "Hello World";
    Console.WriteLine(s1);
    s1.Reverse(); // it didn't reverse the string in place
    Console.WriteLine(s1);

    Array.Reverse(s1.ToArray()); // this didn't reverse the string in place
    Console.WriteLine(s1);

    var s2 = s1.ToArray();
    Array.Reverse(s2); // now that s2 is an array it reversed the s2 in place
    Console.WriteLine(s2);

    var s3 = new string(s1.Reverse().ToArray()); // it didn't reverse the s1 but s3 is reversed
    Console.WriteLine($"{s1} {s3}");

    Console.WriteLine($"{s2} {s3} Equals: {s3 == s2.ToString()} {s3.Equals(s2.ToString())} SequenceEqual: {s3.SequenceEqual(s2)}"); // == didn't work but SequenceEqual did.


}

//CheckingStringEquals();
FindIfDirectedGraphIsValid.Run();

public class Comparator : IComparer<int[]>
{
    public int Compare(int[] arr1, int[] arr2 )
    {
        if(arr1[0] == arr2[0])
        {
            return arr1[1].CompareTo(arr2[1]);
        }

        return arr1[0].CompareTo(arr2[0]);
    }
}
public class Normal
{
    public int EraseOverlapIntervals(int[][] intervals) {
        
        
        Array.Sort(intervals,comparer: new Comparator());
        //Print(intervals);
        return 0;
    }

}

