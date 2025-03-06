package Pieces;

import Board.Board;

public class Queen extends pieces {
    int x = -1;
    int y = -1;

    public Queen(boolean isWhite) {
        super(isWhite);
    }

    public Queen(boolean isWhite, int x, int y) {
        super(isWhite);
        this.x = x;
        this.y = y;
    }

    public int getValue() {
        return 9;
    }

    public String getImage() {
        if (isWhite()) {
            return "/ChessPiecesImages/WhiteQueen.png";
        }
        return "/ChessPiecesImages/BlackQueen.png";
    }

    public boolean canMove(Board board, Position start, Position end) {
        char[][] boardArray = board.getBoard();

        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        char startPiece = boardArray[startX][startY];
        char endPiece = boardArray[endX][endY];

        // Checks if end piece is same color
        if (isWhite() && boardArray[endX][endY] >= 65 && boardArray[endX][endY] <= 90) {
            return false;
        }
        if (!isWhite() && boardArray[endX][endY] >= 97 && boardArray[endX][endY] <= 122) {
            return false;
        }

        if (endPiece != '-' && startPiece == endPiece) {
            return false;
        }

        int xDiff = Math.abs(startX - endX);
        int yDiff = Math.abs(startY - endY);

        if (xDiff == yDiff || startX == endX || startY == endY) {
            return isPathClear(boardArray, start, end);
        }

        return false;
    }

    private boolean isPathClear(char[][] board, Position start, Position end) {
        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        int xDirection = Integer.signum(endX - startX); // +1, -1, or 0 for x direction
        int yDirection = Integer.signum(endY - startY); // +1, -1, or 0 for y direction

        int currentX = startX + xDirection;
        int currentY = startY + yDirection;

        while (currentX != endX || currentY != endY) {
            if (board[currentX][currentY] != '-') {
                return false;
            }
            currentX += xDirection;
            currentY += yDirection;
        }

        return true;
    }
}
