# TEST ADMIN CONNECTION
# import pymongo as pm
# import pprint as pp
# client = pm.MongoClient(<CONNECTION_STRING>)
# db = client.admin
# server_status_result = db.command('serverStatus')
# pp.pprint(server_status_result)
# client.close()

# TEST SIMPLE CRUD
import random as r 
import pymongo as pm

#Step 1: Connect to MongoDB - Note: Change connection string as needed
client = pm.MongoClient(port=27017)
# client = pm.MongoClient(<CONNECTION_STRING>)
db=client.business

#Step 2: Create sample data
names = ['Kitchen','Animal','State', 'Tastey', 'Big','City','Fish', 'Pizza','Goat', 'Salty','Sandwich','Lazy', 'Fun']
company_type = ['LLC','Inc','Company','Corporation']
company_cuisine = ['Pizza', 'Bar Food', 'Fast Food', 'Italian', 'Mexican', 'American', 'Sushi Bar', 'Vegetarian']
for x in range(1, 501):
    business = {
        'name' : names[r.randint(0, (len(names)-1))] + ' ' + names[r.randint(0, (len(names)-1))]  + ' ' + company_type[r.randint(0, (len(company_type)-1))],
        'rating' : r.randint(1, 5),
        'cuisine' : company_cuisine[r.randint(0, (len(company_cuisine)-1))] 
    }

    #Step 3: Insert business object directly into MongoDB via insert_one
    result=db.reviews.insert_one(business)

    #Step 4: Print to the console the ObjectID of the new document
    print('Created {0} of 500 as {1}'.format(x,result.inserted_id))

#Step 5: Tell us that you are done
print('finished creating 500 business reviews')

client.close()
