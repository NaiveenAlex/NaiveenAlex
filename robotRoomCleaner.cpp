/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    int next_step[4][2] ={{-1,0} //up
                     ,{0,1}  //right
                     ,{1,0}  //down
                     ,{0,-1}  //left
                     };
    set<pair<int,int>> visited;
  //  Robot _robot;
    
    void cleanRoomHelper(int row, int col, int dir, Robot& _robot)
    {
        visited.insert(make_pair(row, col));
        _robot.clean();
        for(int i = 0; i < 4; i++)
        {
            int curdir = (dir + i ) % 4;
            int x = row + next_step[curdir][0];
            int y = col + next_step[curdir][1];
            
            if(visited.count(make_pair(x, y))==0 &&
               _robot.move())
            {
                cleanRoomHelper(x, y, curdir, _robot);
                _robot.turnRight();
                _robot.turnRight();
                _robot.move();
                _robot.turnRight();
                _robot.turnRight();
            }
            _robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) 
    {
        cleanRoomHelper(0,0,0, robot);
    }
};
