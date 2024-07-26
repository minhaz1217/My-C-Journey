using BenchmarkDotNet.Running;
using ProblemSolving;

//ProblemSolving.MinimumNumberGame.Runner.Run();

var summary = BenchmarkRunner.Run<Md5VsSha256>();