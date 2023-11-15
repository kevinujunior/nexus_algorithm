import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class JobMatching {

    static void matchJob(int employees, List<List<Integer>> applied, List<List<Integer>> managerPref) {
        int m_pref = managerPref.size();
        List<List<Double>> scores = new ArrayList<>();

        for (int i = 0; i < m_pref; i++) {
            int n_pref = managerPref.get(i).size();
            List<Double> temp = new ArrayList<>();
            for (int j = 0; j < n_pref; j++) {
                int km = managerPref.get(i).get(j) - 1;
                int kn = applied.get(managerPref.get(i).get(j) - 1).size();
                for (int k = 0; k < kn; k++) {
                    if (applied.get(km).get(k) == i + 1) {
                        temp.add((double) 23 / (k + 19) * 29 / (j + 17));
                        break;
                    }
                }
            }
            scores.add(temp);
        }

        List<List<Pair>> employeeScoreList = new ArrayList<>();
        for (int i = 0; i < employees; i++) {
            employeeScoreList.add(new ArrayList<>());
        }

        for (int i = 0; i < managerPref.size(); i++) {
            for (int j = 0; j < managerPref.get(i).size(); j++) {
                int employeeIndex = managerPref.get(i).get(j) - 1;
                employeeScoreList.get(employeeIndex).add(new Pair(i + 1, scores.get(i).get(j)));
            }
        }

        for (List<Pair> employee : employeeScoreList) {
            Collections.sort(employee, Comparator.comparingDouble(a -> -a.second));

            for (Pair jobScore : employee) {
                int job = jobScore.first;
                double score = jobScore.second;
                System.out.print("(" + job + "->" + score + "), ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> applied = List.of(
                List.of(5, 4, 2, 1, 3),
                List.of(8, 7, 6, 2, 4),
                List.of(3, 2, 1, 7, 6),
                List.of(1, 7, 2, 4, 5),
                List.of(5, 4, 2, 3, 1)
        );

        List<List<Integer>> managerPref = List.of(
                List.of(3, 1, 4, 5),
                List.of(4, 1, 3, 5, 2),
                List.of(1, 5, 3),
                List.of(5, 1, 4, 2),
                List.of(4, 1, 5),
                List.of(2, 3),
                List.of(2, 4, 3),
                List.of(2)
        );

        matchJob(5, applied, managerPref);
    }

    static class Pair {
        int first;
        double second;

        Pair(int first, double second) {
            this.first = first;
            this.second = second;
        }
    }
}