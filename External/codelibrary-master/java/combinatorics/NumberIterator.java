package combinatorics;

import java.util.*;
import java.util.function.BiFunction;
import java.util.stream.IntStream;

public class NumberIterator {

    public static long count(long to, int base, BiFunction<int[], Integer, Long> countWithPrefix) {
        List<Integer> revDigits = new ArrayList<>();
        do {
            revDigits.add((int) (to % base));
            to /= base;
        } while (to > 0);
        int n = revDigits.size();
        int[] digits = IntStream.range(0, n).map(i -> revDigits.get(revDigits.size() - 1 - i)).toArray();
        long res = 0;
        for (int i = 0; i < n; i++) {
            int[] prefix = Arrays.copyOf(digits, i + 1);
            for (prefix[i] = 0; prefix[i] < digits[i] + (i == n - 1 ? 1 : 0); ++prefix[i]) {
                res += countWithPrefix.apply(prefix, n - 1 - i);
            }
        }
        return res;
    }

    // Usage example
    public static void main(String[] args) {

        // count numbers consisting only of digits 2 and 5
        long num_2_5 = count(222, 10,
                (prefix, remainingDigits) -> {
                    if (Arrays.equals(prefix, new int[]{0})) return (1L << (remainingDigits + 1)) - 2;

                    boolean all_2_5 = Arrays.stream(prefix).allMatch(v -> v == 2 || v == 5);

                    return all_2_5 ? 1L << remainingDigits : 0;
                });

        System.out.println(7 == num_2_5);
    }
}
