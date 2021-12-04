from __future__ import print_function
import pickle
import os.path
import os

from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request

# If modifying these scopes, delete the file token.pickle.
SCOPES = ['https://www.googleapis.com/auth/spreadsheets.readonly']

# The ID and range of a sample spreadsheet.
SAMPLE_SPREADSHEET_ID = '1uT4RsmSDOSmkEqfRnWkAwDodkWS09-fBS1Ll-rrC9Bs'
SAMPLE_RANGE_NAME = 'read_list'

APP_CREDENTIALS_FILE = os.environ["APP_CREDENTIALS_FILE"]

def get_data_google_sheets():
    """Shows basic usage of the Sheets API.
    Prints values from a sample spreadsheet.
    """
    print("logging in...")
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
                APP_CREDENTIALS_FILE, SCOPES)
            #creds = flow.run_local_server(port=0)
            creds = flow.run_console()
        # Save the credentials for the next run
        with open('token.pickle', 'wb') as token:
            pickle.dump(creds, token)

    service = build('sheets', 'v4', credentials=creds)

    print("getting data...")

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

    print("processing data...")

    # get headers
    # some lines have empty cells on the last columns (on the google sheet)
    # these empty cells don't show up in the retrieved data and need to be added
    headers = data[0]
    for l in data:
        diff = len(headers) - len(l)
        l.extend(['']*diff)

    from jinja2 import Template, Environment

    template = Template('book_list_template.html')


    # build collection of books
    # year <0 -> undatted
    # year 0 -> currently reading
    books = []
    for d in data[1:]:
        b = {h:d[i] for i,h in enumerate(headers)}
        books.append(b)

    for i in range(len(books)):
        books[i]['year'] = int(books[i]['year'])

    def fix_isbn(isbn):
        while len(isbn) < 10:
            isbn = '0' + isbn
        return isbn

    years = {}
    for b in books:
        if b['year'] not in years:
            years[b['year']] = []
        if b['year count']:
            b['year count'] = int(b['year count'])
        b['duration'] = b['read'] if b['read'] else b['audio']
        if not b['cover_url'] and b['isbn-10']:
            b['cover_url'] = 'http://covers.openlibrary.org/b/isbn/{}-M.jpg'.format(fix_isbn(b['isbn-10']))

        years[b['year']].append(b)

    for year, year_books in years.items():
        if year <= 0:
            continue
        years[year] = sorted(years[year],key=lambda x: x['year count'],reverse=True)

    # template_fn = 'book_list_template.html'
    template_fn = 'book_list_template_flipcard.html'

    with open(template_fn) as file_:
        template = Template(file_.read())

    years_lst = [y for y in years.keys() if y < 0]
    years_lst = sorted(years_lst, reverse=True)
    undated_key = "< 2015"
    years_lst.append(undated_key)
    undated_books = []
    for y, books in years.items():
        undated_books += books if y < 0 else []
    years[undated_key] = undated_books


    html = template.render(years_lst=years_lst, years=years, currently_reading=years[0])
    out_fn = 'the_book_list.html'
    with open(out_fn, 'w') as file_:
        file_.write(html)


if __name__ == '__main__':
    run()
