using ProblemSolving.MinimumNumberGame;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemSolving.Template;

public class MergeSort
{
    public static void sort(List<int> arr)
    {
        mergeSort(arr, 0, arr.Count - 1);
    }

    private static void mergeSort(List<int> arr, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            int left = l, right = mid + 1, pos = 0;
            var temp = new List<int>();

            while (left <= mid && right <= r)
            {
                if (arr[left] < arr[right])
                {
                    temp.Add(arr[left]);
                    left++;
                }
                else
                {
                    temp.Add(arr[right]);
                    right++;
                }
            }

            while (left <= mid)
            {
                temp.Add(arr[left++]);
            }
            while (right <= r)
            {
                temp.Add(arr[right++]);
            }

            for (int i = 0; i < temp.Count(); i++)
            {
                arr[i + l] = temp[i];
            }
        }
    }


    public class Runner
    {
        public static void Run()
        {
            var arr = new List<int>();
            for (int i = 0; i < 1000; i++)
            {
                var randomNumber = new Random().Next(1, 1000);
                arr.Add(randomNumber);
            }

            Console.WriteLine("Before");
            for (int i = 0; i < arr.Count; i++)
            {
                if (i > 0)
                {
                    Console.Write(" ");
                }
                Console.Write(arr[i]);
            }

            sort(arr);
            Console.WriteLine("");
            Console.WriteLine("After");
            for (int i = 0; i < arr.Count; i++)
            {
                if (i > 0)
                {
                    Console.Write(" ");
                }
                Console.Write(arr[i]);
            }
        }
    }
}
