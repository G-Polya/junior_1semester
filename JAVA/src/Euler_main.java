import java.util.*;



class Graph
{
    static int k = 400;
    static int gap = 400;

    public int maxSize, size;
    public int maxLen;
    String maxCircuit;
    Vector<String> vertexList = new Vector<String>();
    Vector<Integer> mat = new Vector<Integer>();
    Vector<String> whole_circuit = new Vector<>();

    public Graph(int num)
    {
        size = 0;
        maxSize = num;
        for(int i = 0; i< maxSize;i++)
        {
            for(int j = 0 ; j<maxSize;j++)
                mat.add(0); // 인접행렬 초기화
        }
    }

    public int index(String s, Vector<String> submers)
    {
        int i;
        for(i = 0; i < submers.size();i++)
            if(submers.get(i).equals(s))
                break;

        return i;
    }

    public Integer edge(int row, int col)
    {
        Integer temp = row * maxSize + col;
        return temp;
    }

    public void addVetex(String newVertex)
    {
        vertexList.add(newVertex);
        for(int i =0; i<=size;i++)
        {
            mat.add(0);
            mat.add(0);
        }
        size++;
    }

    public void addEdge(String v1, String v2, Vector<String> submers)
    {
        int row = index(v1,submers);
        int col = index(v2,submers);

        mat.set(edge(row,col), edge(row,col)+1);
    }

    public void showStructure()
    {
        int wt, row, col;

        if(size == 0)
            System.out.println("Empty Graph");
        else
        {
            System.out.println("\nVertex list : ");
            for(row = 0; row < size;row++)
                System.out.println(row + "\t" + vertexList.get(row));

            System.out.println("\nEdge matrix : \n\t");
            for(col = 0; col <size; col++)
                System.out.println(vertexList.get(col)+"\t");
            System.out.println();
            for(row = 0; row < size;row++)
            {
                System.out.println(vertexList.get(row)+"\t");
                for(col = 0; col<size;col++)
                {
                    wt = mat.get(edge(row,col));
                    if(wt == 0)
                        System.out.println("- \t");
                    else
                        System.out.println(wt+"\t");
                }
                System.out.println();
            }
        }
    }

    public int allVisited(String mer, Vector<Integer> adj)
    {
        int e = index(mer,vertexList);
        for(int i = 0; i< maxSize;i++)
            if(adj.get(edge(e,i)) != 0)
                return 0;

        return 1;
    }

    public void countDegree(Vector<String> startVertex)
    {
        for(int i = 0; i< vertexList.size();i++)
        {
            int inDegree =0, outDegree = 0;
            for(int j = 0; j<vertexList.size();j++)
            {
                inDegree += mat.get(edge(j,i));
                outDegree += mat.get(edge(i,j));
            }

            if(outDegree > inDegree)
                startVertex.add(vertexList.get(i));
        }
    }

    public void Eulerian(String mer, Vector<Integer> adj, String circuit)
    {
        int e = index(mer,vertexList);
        Vector<String> temp = new Vector<String>();

        for(int i = 0; i<maxSize;i++)
            if(adj.get(edge(e,i)) != 0)
                temp.add(vertexList.get(i));

        Vector<Integer> adj2 = new Vector<Integer>();
        adj2 = (Vector)adj.clone();

        for(int i = 0; i<temp.size();i++)
        {
            int m = index(temp.get(i), vertexList);

            adj.set(edge(e,m), edge(e,m)-1);

            circuit += vertexList.get(i).substring(k-gap, k);

            if(allVisited(vertexList.get(m), adj) == 1)
            {
                System.out.println(".");
                whole_circuit.add(circuit);
            }
            else
                Eulerian(vertexList.get(m),adj,circuit);

            adj.set(edge(e,m), edge(e,m)+1);
            circuit = circuit.substring(gap);
        }

        return;
    }


    public void DeBrujinize(Vector<String> submers, Vector<String> kmers, Graph graph)
    {
        for(int i = 0; i<submers.size();i++)
            graph.addVetex(submers.get(i));

        for(int i =0;i<kmers.size();i++)
        {
            char[] lsub = new char[k];
            char[] rsub = new char[k];
            for(int j = 0; j < k;j++)
            {
                lsub[j] = kmers.get(i).charAt(j);
                rsub[j] = kmers.get(i).charAt(j+gap);
            }
            //lsub[k] = '\0'; rsub[k] = '\0';
            graph.addEdge(lsub.toString(),rsub.toString(),submers);

        }
        return ;
    }

    public void ParseRead(String genome, Vector<String> reads, String remain)
    {
        int cn = 0;
        for(int i = 0; i<genome.length();i++)
        {
            char[] read = new char[k+gap];

            for(int j = 0; j <k +gap; j++)
                read[j] = genome.charAt(i+j);
            if(read.length == k+gap)
                reads.add(read.toString());
            else
            {
                cn++;
                if(cn == 1)
                {
                    remain = read.toString();
                    remain = remain.substring(k);
                }
            }
        }
    }

    public void ParseKmers(Vector<String> reads, Vector<String> submers)
    {
        for(int i = 0; i< reads.size();i++)
        {
            char[] lsub = new char[k];
            char[] rsub = new char[k];
            for(int j = 0; j<k ;j++)
            {
                lsub[j] = reads.get(i).charAt(j);
                rsub[j] = reads.get(i).charAt(j+gap);
            }
            submers.add(lsub.toString());
            submers.add(rsub.toString());
        }

        Collections.sort(submers);
        HashSet<String> temp_set = new HashSet<String>(submers);
        submers.removeAllElements();
        submers = new Vector<String>(temp_set);
    }

}

public class Euler_main
{
    public static void main(String[] args)
    {
        

    }
}
