package Board;

import Pieces.Position;
import Pieces.pieces;

public class Board {
    private char[][] board;

    public Board() {
        board = new char[8][8];
        initializeBoard();
    }

    public Board(Board board) {
        this.board = new char[8][8];
        char[][] oldBoard = board.getBoard();
        for (int i = 0; i < 8; i++) {
            System.arraycopy(oldBoard[i], 0, this.board[i], 0, 8);
        }
    }

    public void move(Position start, Position end) {
        board[end.getRow()][end.getCol()] = board[start.getRow()][start.getCol()];
        board[start.getRow()][start.getCol()] = '-';
    }


    private void initializeBoard() {
        // UpperCase for white pieces
        board[0][0] = 'R';
        board[0][1] = 'N';
        board[0][2] = 'B';
        board[0][3] = 'Q';
        board[0][4] = 'K';
        board[0][5] = 'B';
        board[0][6] = 'N';
        board[0][7] = 'R';

        board[1][0] = 'P';
        board[1][1] = 'P';
        board[1][2] = 'P';
        board[1][3] = 'P';
        board[1][4] = 'P';
        board[1][5] = 'P';
        board[1][6] = 'P';
        board[1][7] = 'P';

        // LowerCase for black pieces
        board[6][0] = 'p';
        board[6][1] = 'p';
        board[6][2] = 'p';
        board[6][3] = 'p';
        board[6][4] = 'p';
        board[6][5] = 'p';
        board[6][6] = 'p';
        board[6][7] = 'p';

        board[7][0] = 'r';
        board[7][1] = 'n';
        board[7][2] = 'b';
        board[7][3] = 'q';
        board[7][4] = 'k';
        board[7][5] = 'b';
        board[7][6] = 'n';
        board[7][7] = 'r';

        // Fill empty Spaces
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = '-';
            }
        }
    }

    public char[][] getBoard() {
        return board;
    }

    public void printBoard() {

        // Prints Row numbers and Board
        System.out.println("White Pieces: Uppercase");
        System.out.println("Black Pieces: Lowercase");
        for (int i = 0; i < 8; i++) {
            System.out.print((i) + "|");
            for (int j = 0; j < 8; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        // Prints the bottom of the board
        System.out.print("  ");
        for (int i = 0; i < 15; i++) {
            System.out.print("-");
        }
        System.out.println();
        // Prints Column numbers
        System.out.print("  ");
        for (int i = 0; i < 8; i++) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public boolean isValidPosition(Position pos) {
        return pos.getRow() >= 0 && pos.getRow() < 8 && pos.getCol() >= 0 && pos.getCol() < 8;
    }

    public boolean hasPiece(Position pos) {
        return board[pos.getRow()][pos.getCol()] != '-';
    }

    public pieces getPiece(Position pos) {
        char pieceChar = board[pos.getRow()][pos.getCol()];
        return pieces.getPiece(pieceChar);
    }

    public void setPiece(Position pos, char piece) {
        board[pos.getRow()][pos.getCol()] = piece;
    }

}
