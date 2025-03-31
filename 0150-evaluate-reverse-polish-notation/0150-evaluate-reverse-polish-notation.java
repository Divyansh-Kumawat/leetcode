class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk=new Stack<>();
        for(String c:tokens){
            if(c.equals("+")){
                stk.push(stk.pop()+ stk.pop());
            }
            else if(c.equals("-")){
                int second = stk.pop();
                int first = stk.pop();
                stk.push(first - second);
            }
            else if(c.equals("*")){
                stk.push(stk.pop()*stk.pop());
            }
            else if(c.equals("/")){
                int second = stk.pop();
                int first = stk.pop();
                stk.push(first / second);
            }
            else{
                stk.push(Integer.parseInt(c));
            }
        }
        return stk.peek();
    }
}