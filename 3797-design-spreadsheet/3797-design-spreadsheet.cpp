class Spreadsheet {
public:
    int** arr;
    Spreadsheet(int rows)  
    {
        arr = new int*[26];
        for (int j = 0; j <26; j++)
        {
            arr[j] = new int[rows]();
        }
    }

    pair<int, int> parseCell(string cell) {
        int col = cell[0] - 'A'; // Convert 'A'-'Z' to 0-25
        int row = 0;
        for (int i = 1; i < cell.size(); i++) {
            row = row * 10 + (cell[i] - '0'); // Convert multi-digit row number
        }
        return {col, row - 1}; // Convert to 0-based index
    }

    void setCell(string cell, int value) {
        auto [col, row] = parseCell(cell);
        arr[col][row] = value;
    }

    void resetCell(string cell) {
        auto [col, row] = parseCell(cell);
        arr[col][row] = 0;
    }

    int getValue(string formula) {
        if (formula[0] != '=') return stoi(formula); // If it's just a number, return it

        int sum = 0, i = 1; // Start after '='

        while (i < formula.size()) {
            if (isalpha(formula[i])) { // If it's a cell reference
                string cell;
                while (i < formula.size() && (isalpha(formula[i]) || isdigit(formula[i]))) {
                    cell += formula[i++];
                }
                auto [col, row] = parseCell(cell);
                sum += arr[col][row];
            } else if (isdigit(formula[i])) { // If it's a number
                int num = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                sum += num;
            } else { // Skip '+' or other non-relevant characters
                i++;
            }
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */