import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConexaoDB {

	final String driver = "com.mysql.jdbc.Driver";
	final String url = "jdbc:mysql://localhost:3306/";

	public ConexaoDB (String db, String usuario, String senha) {

      	try {

        		Class.forName (driver).newInstance();
			Connection conexao = DriverManager.getConnection (url+db, usuario, senha);
			System.out.println ("Conectou!");
			conexao.close();

        	} catch (SQLException e) {

            	throw new RuntimeException (e);

		} catch (Exception ex) {
            	throw new RuntimeException (ex);
        	}
	}
}

