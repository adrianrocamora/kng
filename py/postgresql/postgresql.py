import psycopg2

my_pw = <PASSWORD>

my_host = '127.0.0.1'


conn = psycopg2.connect(database='testdb01',
                        user = 'postgres',
                        password = my_pw,
                        host = my_host,
                        port = '5432')
print('Opened database successfully')

cur = conn.cursor()
cur.execute('''create table company
            (id int primary key     not null,
            name            text    not null,
            age             int     not null,
            address         char(50),
            salary          real);''')
print('Table created successfully')
conn.commit()
conn.close()

# cur.execute('UPDATE COMPANY set SALARY = 25000.00 where ID = 1')
