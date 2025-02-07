﻿using System.Text;

namespace ProblemSolving.MinimumNumberGame
{
    public class Solution
    {
        public int[] NumberGame(int[] nums)
        {
            var results = new List<int>();
            var pq = new PriorityQueue<int, int>();
            foreach (var num in nums)
            {
                pq.Enqueue(num, num);
            }

            for (int i = 0; i < nums.Length; i++)
            {
                if (i % 2 == 0)
                {
                    var alice = pq.Peek();
                    pq.Dequeue();
                    var bob = pq.Peek();
                    pq.Dequeue();
                    results.Add(bob);
                    results.Add(alice);
                }
            }

            return results.ToArray();
        }
    }

    public class Runner
    {
        public static void Run()
        {
            // arrange
            var testCases = new List<int[]>
            {
                new int[] { 5, 4, 2, 3 },
                new int[] { 2,5 }
            };
            var expectedOutputs = new List<int[]>
            {
                new int[] { 3, 2, 5, 4 },
                new int[] { 5,2 }
            };
            // assign
            var solution = new Solution();


            // assert
            var stringBuilder = new StringBuilder();
            for (int i = 0; i < testCases.Count; i++)
            {
                var testCase = testCases[i];
                var expectedOutput = expectedOutputs[i];
                var actualOutput = solution.NumberGame(testCase);
                var result = expectedOutput.SequenceEqual(actualOutput);
                //Console.WriteLine(String.Join(",", actualOutput));
                //Console.WriteLine(String.Join(",", expectedOutput));
                var verdict = result ? "Passed" : "Failed";
                stringBuilder.Append($"Test {i} - {verdict}\n");
            }
            Console.WriteLine(stringBuilder.ToString());
        }
    }
}
