class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> solved;
		int m = matrix.size();
		if (m == 0) return solved;
		int n = matrix[0].size();
		int startRow = 0;
		int endRow = m - 1;
		int startCol = 0;
		int endCol = n - 1;
		int count = 0;

		while (startRow <= endRow && startCol <= endCol) {
			for (int i = startCol; i <= endCol; i++) {
				solved.push_back(matrix[startRow][i]);
				count++;
			}
			startRow++;
			if (count == m * n) return solved;

			for (int i = startRow; i <= endRow; i++) {
				solved.push_back(matrix[i][endCol]);
				count++;
			}
			endCol--;
			if (count == m * n) return solved;

			for (int i = endCol; i >= startCol; i--) {
				solved.push_back(matrix[endRow][i]);
				count++;
			}
			endRow--;
			if (count == m * n) return solved;

			for (int i = endRow; i >= startRow; i--) {
				solved.push_back(matrix[i][startCol]);
				count++;
			}
			startCol++;
			if (count == m * n) return solved;
		}

		return solved;
	}

};