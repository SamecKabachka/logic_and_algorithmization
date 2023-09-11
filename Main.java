import java.util.*;

class Students{
    String famil,
            name,
            facult;
    int NomZach;

    public Students(String famil, String name, String facult, int nomzach){
        this.famil = famil;
        this.name= name;
        this.facult = facult;
        this.NomZach = nomzach;
    }

    public void print(){
        System.out.println("Студент " + famil + " " + name + " факультета " + facult + " | №" + NomZach);
    }
}

class Lab_1{
    ArrayList<Integer> myArray = new ArrayList();
    int[][] myMatrix;
    int num, columns, rows;


    Lab_1(int num, int rows, int columns) {
        this.num = num;
        this.rows = rows;
        this.columns = columns;
        myMatrix = new int[rows][columns];

        Scanner scanner = new Scanner(System.in);
        System.out.print("Вы хотите ввести массив в ручную (д/н): ");
        char  y_n = scanner.next().charAt(0);

        if (y_n != 'д' || y_n != 'y') {
            System.out.println();
            for (int i = 0; i < num; i++) {
                myArray.add((int) (1 + Math.random() * 9));
                System.out.print(myArray.get(i) + " ");
            }
        } else {
            System.out.println("\nВводите числа: ");

            for (int i = 0; i < num; i++) {
                myArray.add(scanner.nextInt());
            }
        }
        System.out.println("\n");

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                myMatrix[i][j] = (int) (1 + Math.random() * 9);
                System.out.print(myMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void task_1()
    {
        int min = myArray.get(0), max = myArray.get(0);

        for (int i = 1; i < num; i++) {

            if (myArray.get(i)< min) {
                min = myArray.get(i);
            } else if (myArray.get(i) > max) {
                max = myArray.get(i);
            }

        }

        System.out.println();
        System.out.println("макс - мин = " + (max - min));
    }
    public void task_4(int pos) {
        int sum_row = 0, sum_col = 0;
        for(int i = 0; i < rows; i++) sum_col += myMatrix[i][pos];
        for(int i = 0; i < columns; i++) sum_row += myMatrix[pos][i];
        System.out.println("Сумма " + (pos+1) + " столбца: " + sum_col);
        System.out.println("Сумма " + (pos+1) + " строки: " + sum_row);
    }
}

public class Main {
    public static void main(String[] args) {
        int num, rows, columns;
        String famil,
                name,
                facult;
        int NomZach;
        Students[] student = new Students[3];

        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите размер массива: ");
        num = scanner.nextInt();

        System.out.print("Введите кол-во строк матрицы: ");
        rows = scanner.nextInt();
        System.out.print("Введите кол-во столбцов матрицы: ");
        columns = scanner.nextInt();

        Lab_1 t = new Lab_1(num, rows, columns);
        t.task_1();

        System.out.print("Dведите номер столбца/строки: ");
        num = scanner.nextInt();
        t.task_4(--num);
        scanner.nextLine();

        for(int i = 0; i < 3; i++){
            System.out.print("Введите фамилию: ");
            famil = scanner.nextLine();

            System.out.print("Введите имя: ");
            name = scanner.nextLine();

            System.out.print("Введите факультет: ");
            facult = scanner.nextLine();

            System.out.print("Введите № зач. книж.: ");
            NomZach = scanner.nextInt();
            scanner.nextLine();

            student[i] = new Students(famil, name, facult, NomZach);
        }

        for(int i = 0; i < 3; i++){
                student[i].print();
        }

        System.out.print("\n\nВведите параметр поиска ");
        String filter = scanner.nextLine();
        boolean key = true;

        for(int i = 0; i < 3; i++){
            try {
                if (
                        (filter.equals(student[i].famil)) ||
                                (filter.equals(student[i].name)) ||
                                (filter.equals(student[i].facult)) ||
                        (Integer.parseInt(filter)) == student[i].NomZach
                ) {
                    System.out.print("Нашелся (￢‿￢ ) ");
                    student[i].print();
                    key = false;
                }
            }catch (NumberFormatException nfe){
                ;
            }
        }
        if(key) {
            System.out.println("Данного индевида не существует (ಥ﹏ಥ)");
        }
    }
}