package Pieces;

import Board.Board;

public class Knight extends pieces {
    int x = -1;
    int y = -1;

    public Knight(boolean isWhite) {
        super(isWhite);
    }

    public Knight(boolean isWhite, int x, int y) {
        super(isWhite);
        this.x = x;
        this.y = y;
    }

    public String getImage() {
        if (isWhite()) {
            return "/ChessPiecesImages/WhiteKnight.png";
        }
        return "/ChessPiecesImages/BlackKnight.png";
    }

    public boolean canMove(Board board, Position start, Position end) {
        char[][] boardArr = board.getBoard();

        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        if (isWhite() && boardArr[endX][endY] >= 65 && boardArr[endX][endY] <= 90) {
            return false;
        }
        if (!isWhite() && boardArr[endX][endY] >= 97 && boardArr[endX][endY] <= 122) {
            return false;
        }

        char startPoint = boardArr[startX][startY];
        char endPoint = boardArr[endX][endY];

        if (endPoint != '-') {
            if (startPoint == endPoint) {
                return false;
            }
        }

        int DiffX = Math.abs(startX - endX);
        int DiffY = Math.abs(startY - endY);

        return (DiffX == 2 && DiffY == 1) || (DiffX == 1 && DiffY == 2);
    }

    public int getValue() {
        return 3;
    }
}
