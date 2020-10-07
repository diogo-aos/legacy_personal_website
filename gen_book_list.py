from __future__ import print_function
import pickle
import os.path
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request

# If modifying these scopes, delete the file token.pickle.
SCOPES = ['https://www.googleapis.com/auth/spreadsheets.readonly']

# The ID and range of a sample spreadsheet.
SAMPLE_SPREADSHEET_ID = '1uT4RsmSDOSmkEqfRnWkAwDodkWS09-fBS1Ll-rrC9Bs'
SAMPLE_RANGE_NAME = 'read_list'

def get_data_google_sheets():
    """Shows basic usage of the Sheets API.
    Prints values from a sample spreadsheet.
    """
    creds = None
    # The file token.pickle stores the user's access and refresh tokens, and is
    # created automatically when the authorization flow completes for the first
    # time.
    if os.path.exists('token.pickle'):
        with open('token.pickle', 'rb') as token:
            creds = pickle.load(token)
    # If there are no (valid) credentials available, let the user log in.
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file(
                'credentials.json', SCOPES)
            creds = flow.run_local_server(port=0)
        # Save the credentials for the next run
        with open('token.pickle', 'wb') as token:
            pickle.dump(creds, token)

    service = build('sheets', 'v4', credentials=creds)

    # Call the Sheets API
    sheet = service.spreadsheets()
    result = sheet.values().get(spreadsheetId=SAMPLE_SPREADSHEET_ID,
                                range=SAMPLE_RANGE_NAME).execute()
    values = result.get('values', [])

    if not values:
        print('No data found.')
    else:
        return values
        print('Name, Major:')
        for row in values:
            # Print columns A and E, which correspond to indices 0 and 4.
            print('%s, %s' % (row[0], row[4]))
        print(values)

def run():
    data = get_data_google_sheets()

    headers = data[0]
    for l in data:
        diff = len(headers) - len(l)
        l.extend(['']*diff)

    from jinja2 import Template, Environment

    template = Template('book_list_template.html')

    # year 0 -> undatted
    # year -1 -> currently reading
    books = []
    for d in data[1:]:
        b = {h:d[i] for i,h in enumerate(headers)}
        books.append(b)
    
    for i in range(len(books)):
        books[i]['year'] = int(books[i]['year'])


    years = {}
    for b in books:
        if b['year'] not in years:
            years[b['year']] = []
        years[b['year']].append(b)

    def fix_isbn(isbn):
        while len(isbn) < 10:
            isbn = '0' + isbn
        return isbn






    for year, year_books in years.items():
        if year in [-1,0]:
            continue
        for i, b in enumerate(year_books):
            b['year count'] = int(b['year count'])
            b['duration'] = b['read'] if b['read'] else b['audio']
            if b['cover_url']:
                continue
            if b['isbn-10']:
                b['cover_url'] = 'http://covers.openlibrary.org/b/isbn/{}-M.jpg'.format(fix_isbn(b['isbn-10']))
            else:
                b['cover_url'] = ''
        years[year] = sorted(years[year],key=lambda x: x['year count'],reverse=True)
        
        



    # template_fn = 'book_list_template.html'
    template_fn = 'book_list_template_flipcard.html'

    with open(template_fn) as file_:
        template = Template(file_.read())

    years_lst = list(years.keys())
    years_lst = sorted(years_lst, reverse=True)
    years_lst.append('<2015')
    years['<2015'] = years[0]

    if -1 in years_lst:
        years_lst.remove(-1)
    years_lst.remove(0)


    html = template.render(years_lst=years_lst, years=years)
    out_fn = 'the_book_list.html'
    with open(out_fn, 'w') as file_:
        file_.write(html)


if __name__ == '__main__':
    run()
